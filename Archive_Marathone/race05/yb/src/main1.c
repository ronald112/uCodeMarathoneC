#include "header.h"


int main () {
    initscr();    
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    init_pair(2, COLOR_WHITE, COLOR_BLACK);    

    wbkgd(stdscr, COLOR_PAIR(1));

    int max_y = 0, max_x = 0;
    int curpos = 0, startpos = 0;
    getmaxyx(stdscr, max_y, max_x);
    noecho();
    curs_set(FALSE);
    startpos = -1 * (rand() % 20); 
    curpos = startpos;
    int lenght = rand() % 14 - 1;
    while (1) {
        startpos = -1 * (rand() % 20); 
        lenght = rand() % 14 - 1;

        for (int i = 0; i < max_x; i ++) {
        attron(A_BOLD);
        
        // for (int i = 0; i < )
        
        char random_char = (rand() % 93 + 33);

        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        mvaddch(curpos + 1, i, random_char);
        attroff(COLOR_PAIR(2));
        attron(COLOR_PAIR(1));

        
        mvaddch(curpos, i, random_char);
        mvaddch(curpos - lenght, 0, ' ');

        if (curpos - lenght > max_y)
            curpos = startpos;
        
        curpos++;
        }
        msleep(80);
        refresh();
    }

    getch();
    endwin();
    return 0;
}


// // printw("Hello world!\n");
    // char *Hello = "Hello world!";
    // char *Hello1 = "\nO\nR\nL\nD\n!\n";

    // for (int i = 0; i < 13; i++)
        // addch(Hello[i]| A_BOLD); // жирный текст


    // // move(10,10);
    // for (int i = 0; Hello[i] != '\0'; i++) {
    //     // mvaddch(10, 10, Hello[i]);
    //     move(i + 1, (strlen(Hello) / 2) - 1);
    //     addch(Hello[i]);
    // }
    

    // //Получаем максимально возможное количество строк и столбцов для окна stdscr и записываем эти данные в row и col
    // int row = 0, col = 0;
    // getmaxyx(stdscr, row, col);
    // mvwprintw(stdscr, row / 2, (col - strlen(Hello)) / 2, "%s", Hello); // надпись в центре экрана
    // char *The_Words = "The number of rows - %d and collums - %d\n";
    // mvwprintw(stdscr, row - 1, col - strlen(The_Words), The_Words, row, col); // надпись в правом нижнем углу

    // move(1, 1);
    // // char str[100];
    // // addstr("Enter string: ");
    // // getstr(str); //Считваем строку
    // curs_set(0); //"Убиваем" курсор, чтобы не мешался
    // while ( true )
    // {
    // //Перемещаем х-координату как можно дальше вправо, и будем уменьшать её, пока она != 0
    //     for ( int x = 0; x < getmaxy(stdscr); x++ ) 
    //     {
    //         clear();
    //         for (int i = 0; Hello[i] != '\0'; i++) {
    //             mvaddch(x, 0, Hello[i]);
    //             // move(x + 1, 0);
    //             // addch(Hello[i]);
    //         }  
    //         // mvaddstr(x, 0, Hello);
    //         msleep(100);
            
    //         refresh();
    //     }
        
    // }
