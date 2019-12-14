#include "header.h"

static int mx_strlen(const char *s) {
    int len = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        len ++;
    }

    return len;
}

static void mx_printerr(const char *s) {
	write(2, s, mx_strlen(s));
}

static void mx_intro() {
    initscr();
    char *text1 = "\x1B[1;32;40mWake up, Neo..";
    char *text2 = "\x1B[1;32;40mThe Matrix has you..";
    char *text3 = "\x1B[1;32;40mFollow the white rabbit";
    char *text4 = "\x1B[1;32;40mKnock, knock, Neo";
    refresh();
    for(unsigned int i = 0; i < strlen(text1); i++){
        msleep(100);        
        write(1, &text1[i], 1);
    }
    msleep(200);
    clear();
    refresh();
    for(unsigned int i = 0; i < strlen(text2); i++){
        msleep(100);        
        write(1, &text2[i], 1);
    }
    msleep(200);
    clear();
    refresh();
    for(unsigned int i = 0; i < strlen(text3); i++){
        msleep(100);        
        write(1, &text3[i], 1);
    }
    msleep(200);
    clear();
    refresh();
    for(unsigned int i = 0; i < strlen(text4); i++){
        msleep(100);        
        write(1, &text4[i], 1);
    }
    msleep(200);
    clear();
    refresh();
    endwin();
}

int main(int argc, char *argv[]) {
    if (argc != 1)
        mx_printerr("usage: ./race05\n");
    *argv[0] = *argv[0];
    initscr();    
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    init_pair(2, COLOR_WHITE, COLOR_BLACK);    

    wbkgd(stdscr, COLOR_PAIR(1));

    mx_intro();

    int max_y = 0, max_x = 0;    
    getmaxyx(stdscr, max_y, max_x);
    noecho();
    curs_set(FALSE);    
    
    int startpos[max_x];
    int lenght[max_x];
    int curpos[max_x];



    for (int i = 0; i < max_x; i++) {
        startpos[i] = -1 * (rand() % 80);
        curpos[i] = startpos[i];
        lenght[i] = rand() % 50  - 1;
    }
    
    while (1) {
        for (int i = 0; i < max_x; i++) {
            attron(A_BOLD);
        
        char random_char = (rand() % 93 + 33);
        if (i % 2 == 0) {
            random_char = ' ';
        }

        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        mvaddch(curpos[i] + 1, i, random_char);
        attroff(COLOR_PAIR(2));
        attron(COLOR_PAIR(1));
        mvaddch(curpos[i], i, random_char);
        mvaddch(curpos[i] - lenght[i], i, ' ');
        if (curpos[i] - lenght[i] > max_y) {
            curpos[i] = startpos[i];
        }
        curpos[i]++;
        }        
        msleep(80);
        refresh();
    }
    
    getch();
    endwin();
    return 0;
}
