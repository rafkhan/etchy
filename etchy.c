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
  init_pair(3, COLOR_BLACK, COLOR_GREEN);
  init_pair(4, COLOR_BLACK, COLOR_YELLOW);
  init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(6, COLOR_BLACK, COLOR_CYAN);
  init_pair(7, COLOR_BLACK, COLOR_WHITE);

  getmaxyx(stdscr, max_y, max_x);

  xc = yc = 0;
  while(1) {
  	ch = getch();
  	switch(ch) {
     
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
    default:
    	if (47 < ch && ch < 55) {
      	color = ch-48;
      } else {
      	addch(ch);
			}
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
