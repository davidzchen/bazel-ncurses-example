#ifndef FOO_COLOR_H_
#define FOO_COLOR_H_

namespace foo {

#define TEXT_RED 1     // Red text on black
#define TEXT_YELLOW 2  // Yellow text on black
#define TEXT_GREEN 3   // Green text on black
#define TEXT_BLUE 4    // Blue text on black
#define TEXT_CYAN 5    // Cyan text on black
#define TEXT_MAGENTA 6 // Magenta text on black
#define TEXT_WHITE 7   // White text on black

#define TEXT_WHITE_BLACK 10 // Black text on white

// Sets up the ncurses color pairs.
auto SetupColorPairs() -> void;

} // namespace foo

#endif // FOO_COLOR_H_
