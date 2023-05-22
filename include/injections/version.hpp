/**
* @file version.hpp
* @author Matt Williams, (mattltf@protonmail.com)
* @brief Adds version support for Cmake script
* @version 3.2.0
* @date 2021-08-08
*
* @copyright (C) August 8, 2021 Matt Williams
*
*/

#ifndef _INJECTIONS_VERSION_HPP
#define _INJECTIONS_VERSION_HPP

/**
 * @brief The MIT License (MIT)
 * @copyright © 2021 Matt Williams, (mattltf@protonmail.com)
 * @ref https://github.com/thebashpotato
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

#define INJECTIONS_VER_MAJOR 1
#define INJECTIONS_VER_MINOR 0
#define INJECTIONS_VER_PATCH 9

#define INJECTIONS_VERSION \
  (INJECTIONS_VER_MAJOR * 10000 + INJECTIONS_VER_MINOR * 100 + INJECTIONS_VER_PATCH)

#endif// _INJECTIONS_VERSION_HPP
