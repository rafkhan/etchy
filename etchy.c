#include <ncurses.h>
#include <stdlib.h>

void draw_square(int cpair); 

int main(void) {
	
	int ch, xc, yc, max_y, max_x, color = 1;

	/*
	 * Init curses
	 */
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();

	start_color();
	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_BLUE);

	getmaxyx(stdscr, max_y, max_x);

	xc = yc = 0;
	while(1) {
		ch = getch();
		switch(ch) {

			case 'q':
				endwin();
				return 0;
			/*
			 * MOVEMENT KEYS
			 ***************/
			case KEY_UP:
				if(yc > 0) {
					draw_square(color);
					move(--yc, xc);
				}
				break;
			case KEY_LEFT:
				if(xc > 0) {
					draw_square(color);
					move(yc, --xc);
				}
				break;
			case KEY_DOWN:
				if(yc < max_y - 1) {
					draw_square(color);
					move(++yc, xc);
				}
				break;
			case KEY_RIGHT:
				if(xc < max_x - 1) { 
					draw_square(color);
					move(yc, ++xc);
				}
				break;

			case '0':
				color = 0;
				break;
			case '1':
				color = 1;
				break;
			case '2':
				color = 2;
				break;
			default:
				addch(ch);
				xc++;
		}
		refresh();
	}

	getch();
	endwin();

	return 0;
}

void draw_square(int cpair) {
	if(cpair != 0) {
		attron(COLOR_PAIR(cpair));
		addch(' ');
		attroff(COLOR_PAIR(cpair));
	} else {
		addch(' ');
	}
}
