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

#ifndef _INJECTIONS_RETAG_INTERFACE_HPP
#define _INJECTIONS_RETAG_INTERFACE_HPP

#include <algorithm>
#include <injections/interface.hpp>
#include <iostream>
#include <list>

struct user_id;
struct ldap;

namespace injections {
   namespace retag {

      /**
       * @brief
       *
       */
      using Pathname = std::string;
      using Filename = std::string;
      using SharedLibraryName = std::string;
      using MajorMinorPatch = std::string;

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
         virtual void parameters(int argc, const char* argv[]) const pure;

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

      };

      /**
       * @brief test
       * @note available only under test/
       *
       * @param i
       */
      void test(Interface& i);

      /**
       * @brief retag::Injection
       *
       */
      abstract class Injection extends extras::AbstractCustomException
      {
      protected:

         Injection(const std::string& msg, const extras::WhereAmI& whereAmI)
            : AbstractCustomException(msg.c_str(),
               whereAmI._file.c_str(),
               whereAmI._func.c_str(),
               whereAmI._line)
         {
         }
      };

      /**
       * @brief IncorrectParametersException
       *
       */
      concrete class IncorrectParametersException extends Injection
      {
      public:

         IncorrectParametersException(const std::string& msg,
            const extras::WhereAmI& whereAmI)
            : Injection(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const ParameterList& list,
            const extras::WhereAmI& ref)
         {
            ensure(list.size() == 2)
               assume IncorrectParametersException(
                  "syntax: filename version", ref);
         }
      };

      /**
       * @brief IncorrectNumbersException
       *
       */
      concrete class IncorrectNumbersException extends Injection
      {
      public:

         IncorrectNumbersException(const std::string& msg,
            const extras::WhereAmI& whereAmI)
            : Injection(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const std::vector<std::string> parts,
            const extras::WhereAmI& ref)
         {
            ensure(parts.size() == 3)
               assume IncorrectNumbersException(
                  "syntax: ##.##.##", ref);
         }
      };

      /**
       * @brief AlreadyTaggedException
       *
       */
      concrete class AlreadyTaggedException extends Injection
      {
      public:

         AlreadyTaggedException(const std::string& msg,
            const extras::WhereAmI& whereAmI)
            : Injection(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(
            const SharedLibraryName& name,
            const MajorMinorPatch& mmp,
            const extras::WhereAmI& ref)
         {
            ensure(!name.empty())
               assume AlreadyTaggedException(
                  "SharedLibraryName not specified", ref);
            ensure(!mmp.empty())
               assume AlreadyTaggedException(
                  "MajorMinorPatch not specified", ref);
            Filename new_name = name + "." + mmp;
            mask(extras::file::Found, AlreadyTagged, new_name, ref);
         }
      };

   } // namespace retag
} // namespace extras

#endif // _INJECTIONS_RETAG_INTERFACE_HPP
