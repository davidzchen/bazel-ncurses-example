#include <curses.h>

#include <clocale>
#include <cstdlib>
#include <iostream>

#include "foo/color.h"

auto main(int argc, char **argv) -> int {
  std::cerr << "00\n";
  setlocale(LC_ALL, "");
  std::cerr << "11\n";
  initscr();
  std::cerr << "22\n";
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

  return EXIT_SUCCESS;
}
