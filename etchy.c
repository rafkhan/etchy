/**********************
 * Contributors:      *
 * 	- rafkhan         *
 * 	- uiri            *
 * 	- tacticalgenius  *
 **********************/

#include <ncurses.h>
#include <stdlib.h>

void init(void);
void draw_color(int cpair);

int main(void) {
	int ch, xc, yc, max_y, max_x, color;
	color = 1;

	init(); /* initialize curses */
	getmaxyx(stdscr, max_y, max_x);

	xc = yc = 0; /* Set initial position */
	while(1) {
		
		/* ch = key pressed */
		ch = getch(); 

		switch(ch) {
			/*
			 * Movement keys
			 * Draws a coloured box
			 */
			case KEY_UP:
				if(yc > 0) {
					draw_color(color);
					move(--yc, xc);
				}
				break;
			case KEY_DOWN:
				if(yc < max_y - 1) {
					draw_color(color);
					move(++yc, xc);
				}
				break;
			case KEY_LEFT:
				if(xc > 0) {
					draw_color(color);
					move(yc, --xc);
				}
				break;
			case KEY_RIGHT:
				if(xc < max_x - 1) {
					draw_color(color);
					move(yc, ++xc);
				}
				break;

			/*
			 * Color keys
			 * 
			 * Macro for f-key case statement below
			 */
			#define F_MACRO(i) case KEY_F(i):color = i;break;

			F_MACRO(1);
			F_MACRO(2);
			F_MACRO(3);
			F_MACRO(4);
			F_MACRO(5);
			F_MACRO(6);
			F_MACRO(7);
			F_MACRO(8);

			default:
				/* Printable ascii chars */
				if(ch >= ' ' && ch <= '~') {
					if(xc < max_x - 1) {
						attron(COLOR_PAIR(color));
						addch(ch);
						attroff(COLOR_PAIR(color));
						move(yc, ++xc);
					} else {
						attron(COLOR_PAIR(color));
						addch(ch);
						attroff(COLOR_PAIR(color));
						/* set coords to beginning of next line */
						xc = 0;
						move(++yc, xc);
					}
				}
		}

		/* redraw ncurses screen */
		refresh();
	}
}

/*
 * Draws a box, takes a colour pair
 * as a parameter, which are defined below
 */
void draw_color(int cpair) {
	attron(COLOR_PAIR(cpair));
	addch(' ');
	attroff(COLOR_PAIR(cpair));
}

/*
 * Initialize curses and color pairs
 */
void init(void) {
	initscr(); /* get screen */
	keypad(stdscr, TRUE); /* enable keypad */
	cbreak();
	noecho(); /* Do not just display keystrokes */

	/* Color config */
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	init_pair(4, COLOR_WHITE, COLOR_GREEN);
	init_pair(5, COLOR_BLACK, COLOR_YELLOW);
	init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(7, COLOR_BLACK, COLOR_CYAN);
	init_pair(8, COLOR_BLACK, COLOR_WHITE);
}
