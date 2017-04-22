#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <menu.h>
#include <string.h>

// http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/menus.html

/********************************/
/********* INTERFACE ************/
/********************************/

void menu();
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

#endif
