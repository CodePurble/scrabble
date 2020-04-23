#ifndef UTILS_H
#define UTILS_H
#include <iostream>

#define DEBUG(x, y) std::cout << x << ":" << y << std::endl
#define NUM_ROWS 15
#define NUM_COLS 15


/*
 * ANSI escape codes for colour
 *
 * \033[38;2;<r>;<g>;<b>m     #Select RGB foreground color
 * \033[48;2;<r>;<g>;<b>m     #Select RGB background color
 *
 * Use like this-
 * Pinkish text on a brownish background
 * \033[38;2;255;82;197;48;2;155;106;0mHello
 */
inline void BOLD(std::string x) { std::cout << "\033[1m" + x + "\033[0m"; }
inline void BOLD_BRIGHT_GREEN(std::string x) { std::cout << "\033[1;38;2;0;255;19m" + x + "\033[0m"; }
inline void BOLD_CYAN(std::string x) { std::cout << "\033[1;38;2;51;177;255m" + x + "\033[0m"; }
inline void BOLD_BLUE(std::string x) { std::cout << "\033[1;38;2;0;0;255m" + x + "\033[0m"; }
inline void BOLD_PINK(std::string x) { std::cout << "\033[1;38;2;203;6;104m" + x + "\033[0m"; }
inline void BOLD_ORANGE(std::string x) { std::cout << "\033[1;38;2;248;28;28m" + x + "\033[0m"; }
inline void BOLD_BROWN(std::string x) { std::cout << "\033[1;38;2;149;0;19m" + x + "\033[0m"; }
inline void BOLD_WHITE(std::string x) { std::cout << "\033[1;38;2;255;255;255m" + x + "\033[0m"; }

#endif
