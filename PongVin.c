#include <ncurses.h>
#include <unistd.h>
#include <string.h>

int main() {

    // object scr
    short int scrx;
    short int scry;
    short int scrc;
    bool scrmovhor;
    bool scrmovver;

    int i = 0;
    int cont = 0;
    bool end = false;

    initscr();
    cbreak();
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    keypad(stdscr,true);
    noecho();
    curs_set(0);

    getmaxyx(stdscr, scry, scrx);

    // object b1
    short int b1x = scrx - 2;
    short int b1y = scry / 2;
    short int b1c = 0;
    bool b1movhor = false;
    bool b1movver = false;

    // object b2
    short int b2x = 1;
    short int b2y = scry / 2;
    short int b2c = 0;
    bool b2movhor = false;
    bool b2movver = false;

    // object b
    short int bx = scrx / 2;
    short int by = scry / 2;
    short int bc = 0;
    bool bmovhor = false;
    bool bmovver = false;

    mvprintw(4, (scrx - strlen(" oooooooooo                                  "))/2, " oooooooooo                                  ");
    mvprintw(5, (scrx - strlen(" 888    888  ooooooo    ooooooo    oooooooo8 "))/2, " 888    888  ooooooo    ooooooo    oooooooo8 ");
    mvprintw(6, (scrx - strlen(" 888oooo88 888     888 888   888  888    88o "))/2, " 888oooo88 888     888 888   888  888    88o ");
    mvprintw(7, (scrx - strlen(" 888       888     888 888   888   888oo888o "))/2, " 888       888     888 888   888   888oo888o ");
    mvprintw(8, (scrx - strlen(" 888       888     888 888   888   888oo888o "))/2, " 888       888     888 888   888   888oo888o ");
    mvprintw(9, (scrx - strlen(" 888       888     888 888   888   888oo888o "))/2, " 888       888     888 888   888   888oo888o ");
    mvprintw(10, (scrx - strlen("o888o        88ooo88  o888o o888o 888     888"))/2, "o888o        88ooo88  o888o o888o 888     888");
    mvprintw(11, (scrx - strlen("                                   888ooo888 "))/2, "                                   888ooo888 ");

    mvprintw(13, (scrx - strlen("Any questions please send me at vtverzosa@student.apc.edu.ph"))/2, "Any questions please send me at vtverzosa@student.apc.edu.ph");
    mvprintw(14, (scrx - strlen("Controls for Player 1 are 'w' and 's'"))/2, "Controls for Player 1 are 'w' and 's'");
    mvprintw(15, (scrx - strlen("Controls for Player 2 are arrow keys"))/2, "Controls for Player 2 are arrow keys");
    mvprintw(16, (scrx - strlen("Push ANY key to start, 'p' for pause and ESC to quit"))/2, "Push ANY key to start, 'p' for pause and ESC to quit");

    getch();

    for(nodelay(stdscr,1); !end; usleep(4000)) {
        if(++cont%16==0){
            if((by == scry - 1) || (by == 1))
                bmovver = !bmovver;

            if((bx >= scrx - 2) || (bx <= 2)) {
                bmovhor = !bmovhor;
                if((by == b1y - 1) || (by == b2y - 1)) {
                    bmovver = false;
                } else if((by == b1y + 1) || (by == b2y + 1)) {
                    bmovver = true;
                } else if((by != b1y) && (by != b2y)) {
                    (bx >= scrx - 2) ? b1c++: b2c++;
                    bx = scrx / 2;
                    by = scry / 2;
                }
            }
            bx = bmovhor ? bx + 1 : bx - 1;
            by = bmovver ? by + 1 : by - 1;

            if(b1y <= 1)
                b1y = scry - 2;
            if(b1y >= scry - 1)
                b1y = 2;
            if(b2y <= 1)
                b2y = scry - 2;
            if(b2y >= scry - 1)
                b2y = 2;
        }

        switch(getch()) {
            case KEY_DOWN: b1y++; b1y++; break;
            case KEY_UP:   b1y--; b1y--; break;
            case 'w':      b2y--; b2y--; break;
            case 's':      b2y++; b2y++; break;
            case 'p':      getchar(); break;
            case 0x1B:    endwin(); end++; break;
        }

        erase();

        mvprintw(2, scrx / 2 - 2,"%i | %i", b1c, b2c);
        mvvline(0, scrx / 2, ACS_VLINE, scry);

        attron(COLOR_PAIR(1));

        mvprintw(by, bx, "o");

        for(i = -1; i < 2; i++){
            mvprintw(b1y + i, b1x, "|");
            mvprintw(b2y + i, b2x, "|");
        }
        attroff(COLOR_PAIR(1));
    }

    endwin();
    return 0;
}
