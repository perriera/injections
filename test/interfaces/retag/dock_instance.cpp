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

#include <extras/docking/DockIt.hpp>
#include <extras/file/clazz.hpp>
#include <reensure/retag/clazz.hpp>
#include <extras/strings.hpp>
#include <extras/version.hpp>
#include <iostream>
#include <sstream>

 //
 // https://github.com/eranpeer/FakeIt/wiki/Quickstart
 //

using namespace reensure::retag;
using namespace extras;

/**
 * @brief dock retag::Interface
 *
 */
SCENARIO("Dock retag::Interface", "[dock retag::Interface]")
{
    /**
     * @brief determine fullpath
     *
     */
    Number major_no = std::to_string(EXTRAS_VER_MAJOR);
    Number minor_no = std::to_string(EXTRAS_VER_MINOR);
    Number patch_no = std::to_string(EXTRAS_VER_PATCH);
    Filename testarea = "build/testarea/";
    Filename filename = "libsisutil.so";
    Filename fullpath = testarea + filename;
    Filename symlink1 = fullpath + "." + major_no;
    Filename symlink2 = symlink1 + "." + minor_no;
    Filename symlink3 = symlink2 + "." + patch_no;
    Filename before = testarea + filename;
    Filename after = symlink3;

    /**
     * @brief construct dock for interface
     *
     */
     //    retag::Instance dock(fullpath, major_no, minor_no, patch_no);
     //    retag::Interface& i = dock;
     //    retag::test_execute(i);

     /**
      * @brief missing parameter test
      */
}
