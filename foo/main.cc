#include <curses.h>

#include <clocale>
#include <cstdlib>

#include "foo/color.h"

auto main(int argc, char **argv) -> int {
  setlocale(LC_ALL, "");
  initscr();
  noecho();
  curs_set(0);

  if (!has_colors()) {
    printw("ERROR: Colors are not supported. Press any key to exit.");
    getch();
    endwin();
    return EXIT_FAILURE;
  }
  start_color();
  foo::SetupColorPairs();

  WINDOW *stdwin = stdscr;
  wrefresh(stdwin);
  wrefresh(stdscr);
  wborder(stdwin, 0, 0, 0, 0, 0, 0, 0, 0);
  wprintw(stdwin, "Hello World");

  getch();
  endwin();

  return EXIT_SUCCESS;
}
