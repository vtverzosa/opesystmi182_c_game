#include <ncurses.h>
typedef struct {short int x,y,c ; bool movhor, movver;} object;

main () {
	object scr; int i = 0, cont = 0; bool end = false;
	initscr();
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_WHITE);
	keypad(stdscr,true);
  	noecho();
  	curs_set(0);
  	getmaxyx(stdscr,scr.y,scr.x);
  	object b1={scr.x-2,scr.y/2,0,false,false},b2={1,scr.y/2,0,false,false},b={scr.x/2,scr.y/2,0,false,false};
  	mvprintw(4,0,"\t           oooooooooo                                        \n"
               	     "\t           888    888  ooooooo    ooooooo    oooooooo8       \n"
               	     "\t           888oooo88 888     888 888   888  888    88o       \n"
                     "\t           888       888     888 888   888   888oo888o       \n"
                     "\t          o888o        88ooo88  o888o o888o 888     888      \n"
                     "\t                                             888ooo888     \n\n"
               "\t Any questions please send me at vicente.bolea@gmail.com     \n"
               "\t \t\t\tPlayer 1 your controls are 'a' and 'q'                \n"
               "\t \t\t\tPlayer 2 your controls are the arrows of the keyboard \n"
               "\t \t\t\tPush ANY key to start, 'p' for pause and ESC to quit" ); 
  getch();


        if ((b.y==b1.y-1)||(b.y==b2.y-1)) {
          b.movver=false;
        } else if ((b.y==b1.y+1)||(b.y==b2.y+1)) {
          b.movver=true;
        } else if ((b.y != b1.y) && (b.y != b2.y)) {
          (b.x>=scr.x-2) ? b1.c++: b2.c++;
          b.x=scr.x/2;
          b.y=scr.y/2;
        }
      }
      b.x=b.movhor ? b.x+1 : b.x-1;
      b.y=b.movver ? b.y+1 : b.y-1;

}
