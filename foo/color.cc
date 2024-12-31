#include "foo/color.h"

#include <curses.h>

namespace foo {

auto SetupColorPairs() -> void {
  init_pair(TEXT_RED, COLOR_RED, COLOR_BLACK);
  init_pair(TEXT_YELLOW, COLOR_YELLOW, COLOR_BLACK);
  init_pair(TEXT_GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(TEXT_BLUE, COLOR_BLUE, COLOR_BLACK);
  init_pair(TEXT_CYAN, COLOR_CYAN, COLOR_BLACK);
  init_pair(TEXT_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(TEXT_WHITE, COLOR_WHITE, COLOR_BLACK);

  init_pair(TEXT_WHITE_BLACK, COLOR_BLACK, COLOR_WHITE);
}

} // namespace foo
