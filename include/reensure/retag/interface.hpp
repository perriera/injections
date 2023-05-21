/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 * @ref https://github.com/perriera
 *
 * Permission  is  hereby  granted, free  of  charge, to  any person  obtaining
 * a copy of this software and associated documentation files (the “Software”),
 * to deal in the Software  without restriction,  including  without limitation
 * the rights to  use,  copy,  modify,  merge, publish, distribute, sublicense,
 * and/or sell  copies of the  Software,  and  to  permit  persons  to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice  and this permission  notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS  PROVIDED “AS IS”,  WITHOUT WARRANTY  OF ANY  KIND,  EXPRESS
 * OR IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR  COPYRIGHT HOLDERS BE  LIABLE FOR ANY  CLAIM,  DAMAGES  OR  OTHER
 * LIABILITY,  WHETHER IN  AN ACTION  OF CONTRACT,  TORT OR  OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#ifndef _EXTRAS_RETAG_INTERFACE_HPP
#define _EXTRAS_RETAG_INTERFACE_HPP

#include <algorithm>
#include <extras/interfaces.hpp>
#include <iostream>
#include <list>

struct user_id;
struct ldap;

namespace reensure {
   namespace retag {

      /**
       * @brief
       *
       */
      using Pathname = std::string;
      using Filename = std::string;
      using Number = std::string;
      using Cmd = std::string;
      using Param = std::string;
      using ParameterList = std::vector<std::string>;

      /**
       * @brief retag::Interface
       *
       */
      interface Interface
      {

         /**
          * @brief parameters
          *
          * @param argc
          * @param argv
          */
         virtual void parameters(int argc, const char* argv[]) pure;

         /**
          * @brief execute
          *
          */
         virtual void execute(int argc, const char* argv[]) const pure;

         /**
          * @brief major, minor, patch
          *
          * @return Number
          */
         virtual Number major_no() const pure;
         virtual Number minor_no() const pure;
         virtual Number patch_no() const pure;

         /**
          * @brief
          *
          * @return Filename
          */
         virtual Filename newTag() const pure;
      };

      /**
       * @brief test
       * @note available only under test/
       *
       * @param i
       */
      void test(Interface& i);
      void test_execute(Interface& i);
      void test_parameters(Interface& i);

      /**
       * @brief retag::Exception
       *
       */
      concrete class Exception extends extras::AbstractCustomException
      {
      protected:

         Exception(const std::string& msg, const extras::WhereAmI& whereAmI)
            : AbstractCustomException(msg.c_str(),
               whereAmI._file.c_str(),
               whereAmI._func.c_str(),
               whereAmI._line)
         {
         }
      };

      // /**
      //  * @brief FileNotFoundException
      //  *
      //  */
      // concrete class NotFoundException extends Exception
      // {
      //  public:

      //    NotFoundException(const std::string& msg,
      //                      const extras::WhereAmI& whereAmI)
      //      : Exception(msg, whereAmI)
      //    {
      //    }

      //    virtual char const* what() const noexcept { return _msg.c_str(); }

      //    static void assertion(const Filename& filename,
      //                          const extras::WhereAmI& ref);
      // };

      /**
       * @brief IncorrectParametersException
       *
       */
      concrete class IncorrectParametersException extends Exception
      {
      public:

         IncorrectParametersException(const std::string& msg,
            const extras::WhereAmI& whereAmI)
            : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const ParameterList& list,
            const extras::WhereAmI& ref)
         {
            _assume(list.size() != 2) _ensure IncorrectParametersException(
               "syntax: filename version", ref);
         }
      };

      /**
       * @brief IncorrectNumbersException
       *
       */
      concrete class IncorrectNumbersException extends Exception
      {
      public:

         IncorrectNumbersException(const std::string& msg,
            const extras::WhereAmI& whereAmI)
            : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const std::vector<std::string> parts,
            const extras::WhereAmI& ref)
         {
            _assume(parts.size() != 3)
               _ensure IncorrectNumbersException("syntax: ##.##.##", ref);
         }
      };

   } // namespace retag
} // namespace extras

#endif // _EXTRAS_RETAG_INTERFACE_HPP
