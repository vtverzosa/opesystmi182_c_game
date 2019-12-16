#include <ncurses.h>
typedef struct {short int x,y,c ; bool movhor, movver;} object;

main () {
	object scr; int i = 0, cont = 0; bool end = false;
	initscr();
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_WHITE);

}
