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

#include <reassure/game/clazz.hpp>
#include <extras/interfaces.hpp>
#include <iostream>

using namespace std;
using namespace reassure;

namespace reassure {
  namespace reassign {
    namespace game {

      void ChessGame::moves() const {}

      bool ChessGame::exists() const
      {
        return true;
      }

      bool ChessGame::piece(int, int) const
      {
        return true;
      }

      bool ChessGame::zone(int row, int col) const
      {
        game::EndOfGameReachedException::assertion(
          row, col, "sample", __INFO__);
        return row == _x && col == _y;
      }

    }
  }
}