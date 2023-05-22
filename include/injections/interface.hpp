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

#ifndef _INJECTIONS_INTERFACE_HPP
#define _INJECTIONS_INTERFACE_HPP

#include <extras/language/interfaces.hpp>

namespace injections {

#define assume throw
#define ensure(x) if (!(x))

   /**
    * @brief ignore keywords
    *
    */
#define ignore0(a, b) a##Exception::assertion(b)
#define ignore1(a, b, c) a##Exception::assertion(b, c)
#define ignore2(a, b, c, d) a##Exception::assertion(b, c, d)
#define ignore3(a, b, c, d, e) a##Exception::assertion(b, c, d, e)
#define ignore4(a, b, c, d, e, f) a##Exception::assertion(b, c, d, e, f)
#define ignore5(a, b, c, d, e, f, g) a##Exception::assertion(b, c, d, e, f, g)
#define ignore6(a, b, c, d, e, f, g, h)                                        \
   a##Exception::assertion(b, c, d, e, f, g, h)
#define ignore7(a, b, c, d, e, f, g, h, i)                                     \
   a##Exception::assertion(b, c, d, e, f, g, h, i)
#define ignore8(a, b, c, d, e, f, g, h, i, j)                                  \
   a##Exception::assertion(b, c, d, e, f, g, h, i, j)
    // #define ignore(a, b, c) ignore1(a, b, c)

 /**
  * @brief inject keywords
  *
  */
#define inject0 ignore0
#define inject1 ignore1
#define inject2 ignore2
#define inject3 ignore3
#define inject4 ignore4
#define inject5 ignore5
#define inject6 ignore6
#define inject7 ignore7
#define inject8 ignore8
#define inject ignore1

} // namespace extras

/**
 * @brief mask
 *
 */
#define mask(a, b, c, d)                                                       \
   try {                                                                       \
      inject(a, c, d);                                                         \
   } catch (const a##Exception& ex) {                                          \
      assume b##Exception(c, d);                                               \
   }

#endif // _INJECTIONS_INTERFACE_HPP
