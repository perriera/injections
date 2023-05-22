/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
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

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

#include <extras/docking/DockIt.hpp>
#include <extras/file/clazz.hpp>
#include <reensure/retag/interface.hpp>
#include <extras/strings.hpp>
#include <extras/version.hpp>
#include <iostream>
#include <sstream>

 //
 // https://github.com/eranpeer/FakeIt/wiki/Quickstart
 //

using namespace reensure::retag;
using namespace extras;
using namespace fakeit;

/**
 * @brief dock retag::Interface
 *
 */
namespace reensure {
   namespace retag {

      void test(Interface& i)
      {

         /**
          * @brief parameters
          *
          */

         const char* argv[] = { "build/testarea/libsisutil.so", "9.24.0" };
         int argc = 2;

         /**
          * @brief determine fullpath
          *
          */
         auto major_no = "9";
         auto minor_no = "24";
         auto patch_no = "0";
         Filename testarea = "build/testarea/";
         Filename filename = "libsisutil.so";
         Filename fullpath = testarea + filename;
         Filename symlink1 = fullpath + "." + major_no;
         Filename symlink2 = symlink1 + "." + minor_no;
         Filename symlink3 = symlink2 + "." + patch_no;
         Filename before = testarea + filename;
         Filename after = symlink3;

         /**
          * @brief prepare test area
          *
          */

         system("rm -rf build/testarea");
         system("mkdir build/testarea");
         system("cp test/etc/retag/librandom.sol build/testarea/libsisutil.so");
         file::NotFoundException::assertion(before, __INFO__);

         /**
          * @brief test the interface
          * @note retag libsisutil.so (that has NOT been retagged)
          */

         file::NotFoundException::assertion(before, __INFO__);
         file::FoundException::assertion(after, __INFO__);
         file::FoundException::assertion(symlink1, __INFO__);
         file::FoundException::assertion(symlink2, __INFO__);
         file::FoundException::assertion(symlink3, __INFO__);
         i.execute(argc, argv);
         file::NotFoundException::assertion(before, __INFO__);
         file::NotFoundException::assertion(after, __INFO__);
         file::NotFoundException::assertion(symlink1, __INFO__);
         file::NotFoundException::assertion(symlink2, __INFO__);
         file::NotFoundException::assertion(symlink3, __INFO__);

         /**
          * @brief test the interface
          * @note retag libsisutil.so (that HAS been retagged)
          */

         file::NotFoundException::assertion(before, __INFO__);
         file::NotFoundException::assertion(after, __INFO__);
         file::NotFoundException::assertion(symlink1, __INFO__);
         file::NotFoundException::assertion(symlink2, __INFO__);
         file::NotFoundException::assertion(symlink3, __INFO__);
         REQUIRE_THROWS_AS(i.execute(argc, argv), AlreadyTaggedException);
         file::NotFoundException::assertion(before, __INFO__);
         file::NotFoundException::assertion(after, __INFO__);
         file::NotFoundException::assertion(symlink1, __INFO__);
         file::NotFoundException::assertion(symlink2, __INFO__);
         file::NotFoundException::assertion(symlink3, __INFO__);
      }

   }
}
