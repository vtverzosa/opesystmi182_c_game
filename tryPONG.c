#include <ncurses.h>
#include <string.h>

int main () {
    // struct object
    bool movhor;
    bool movver;

    // scr object
    int i = 0;
    int cont = 0;
    bool end = FALSE;

    int screeny = 0; // initialization of screen height
    int screenx = 0; // initialization of screen width

	initscr(); // initialize screen
    cbreak();
    noecho();
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_MAGENTA);
	keypad(stdscr, TRUE); // turn on arrow keys
    curs_set(0); // hide cursor indicator

    getmaxyx(stdscr, screeny, screenx); // declare screen height and width

    // b object
    int bx = screenx/2;
    int by = screeny/2;
    int bc = 0;
    int bxb = FALSE;
    int byb = FALSE;

    // b1 object
    int b1x = screenx - 2;
    int b1y = screeny/2;
    int b1c = 0;
    int b1xb = FALSE;
    int b1yb = FALSE;

    // b2 object
    int b2x = 1;
    int b2y = screeny/2;
    int b2c = 0;
    int b2xb = FALSE;
    int b2yb = FALSE;

    mvprintw(4, (screenx + strlen(" oooooooooo                                  "))/2, " oooooooooo                                  ");
    mvprintw(5, (screenx + strlen(" 888    888  ooooooo    ooooooo    oooooooo8 "))/2, " 888    888  ooooooo    ooooooo    oooooooo8 ");
    mvprintw(6, (screenx + strlen(" 888oooo88 888     888 888   888  888    88o "))/2, " 888oooo88 888     888 888   888  888    88o ");
    mvprintw(7, (screenx + strlen(" 888       888     888 888   888   888oo888o "))/2, " 888       888     888 888   888   888oo888o ");
    mvprintw(8, (screenx + strlen(" 888       888     888 888   888   888       "))/2, " 888       888     888 888   888   888oo888o ");
    mvprintw(9, (screenx + strlen(" 888       888     888 888   888   888oo888o "))/2, " 888       888     888 888   888   888oo888o ");
    mvprintw(10, (screenx + strlen("o888o       88ooo88  o888o o888o 888     888"))/2, "o888o        88ooo88  o888o o888o 888     888");
    mvprintw(11, (screenx + strlen("                                   888ooo888 "))/2, "                                   888ooo888 ");

    mvprintw(13, (screenx + strlen("Any questions please send me at vtverzosa@student.apc.edu.ph"))/2, "Any questions please send me at vtverzosa@student.apc.edu.ph");
    mvprintw(14, (screenx + strlen("Controls for Player 1 are 'w' and 's'"))/2, "Controls for Player 1 are 'w' and 's'");
    mvprintw(15, (screenx + strlen("Controls for Player 2 are arrow keys"))/2, "Controls for Player 2 are arrow keys");
    mvprintw(16, (screenx + strlen("Push ANY key to start, 'p' for pause and ESC to quit"))/2, "Push ANY key to start, 'p' for pause and ESC to quit");

    getch();


    if ((by == b1y - 1) || (by == b2y - 1)) {
        movver = FALSE;
    } else if ((by == b1y + 1) || (by == b2y + 1)) {
        movver = TRUE;
    } else if ((by != b1y) && (by != b2y)) {
        (bx >= screenx - 2) ? b1c++ : b2c++;
        bx = screenx/2;
        by = screeny/2;
    }

    bx == movhor ? bx++ : bx--;
    by == movver ? by++ : by--;

    if (b1y <= 1)
        b1y = screeny - 2;
    if (b1y >= screeny - 1)
        b1y = 2;
    if (b2y <= 1)
        b2y = screeny - 2;
    if (b2y >= screeny - 1)
        b2y = 2;


    switch (getch()) {
        case KEY_DOWN: b1y++; break;
        case KEY_UP:   b1y--; break;
        case 'w':      b2y--; break;
        case 's':      b2y++; break;
        case 'p':      getchar(); break;
        case 0x1B:    endwin(); end++; break;
    }

    erase();

    mvprintw(2, screenx / 2 - 2, "%i | %i", b1c, b2c);

    mvvline(0, screenx / 2, ACS_VLINE, screeny);
    attron(COLOR_PAIR(1));

    mvprintw(by, bx, "O");

    for(i = -1; i < 2; i++) {
        mvprintw(b1y + i, b1x, "|");
        mvprintw(b2y + i, b2x, "|");
    }

    attroff(COLOR_PAIR(2));

    endwin();
    return 0;
}
