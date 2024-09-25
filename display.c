#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include "display.h"

#define WHITE 1
#define BLACK 0
#define YELLOW 2
#define RED 3
#define CYAN 5
int open_display(void) {
    // Initialize the ncurses library
    initscr();

    // Check if initialization was successful
    if (initscr() == NULL) {
        return 0;  // Return 0 to indicate failure
    }

    // Initialize color pairs as needed
    start_color();
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    // Initialize other color pairs as needed

    return 1;  // Return 1 to indicate success
}
void display_time(int hours, int minutes, int seconds){
    uint16_t pixel[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            pixel[i][j] = BLACK;
        }
    }    
    display_colons(pixel);
    display_seconds(pixel,seconds);
    display_minutes(pixel,minutes);
    display_hours(pixel,hours);
    draw_grid(pixel);
    sleep(1);

}
void display_colons(uint16_t pixels[8][8]) {
        pixels[2][2] = WHITE;
        pixels[2][3] = WHITE;
        pixels[3][2] = WHITE;
        pixels[3][3] = WHITE;

        pixels[2][5] = WHITE;
        pixels[2][6] = WHITE;
        pixels[3][5] = WHITE;
        pixels[3][6] = WHITE;

        pixels[6][2] = WHITE;
        pixels[6][3] = WHITE;
        pixels[5][2] = WHITE;
        pixels[5][3] = WHITE;

        pixels[6][5] = WHITE;
        pixels[6][6] = WHITE;
        pixels[5][5] = WHITE;
        pixels[5][6] = WHITE;
}
void display_hours(uint16_t pixels[8][8], int hours) {
    for (int i = 6; i > 0; i--) {
        if (hours % 2) {
            pixels[i+1][1] = RED;
        }
        hours /= 2;
    }
}
void display_minutes(uint16_t pixels[8][8], int minutes) {
for (int i = 6; i > 0; i--) {
        if (minutes % 2) {
            pixels[i+1][4] = YELLOW;
        }
        minutes /= 2;
    }
}
void display_seconds(uint16_t pixels[8][8], int seconds) {
    for (int i = 6; i > 0; i--) {
        if (seconds % 2) {
            pixels[i+1][7] = CYAN;
        }
        seconds /= 2;
    }
}
void close_display(void){
endwin();
}
void draw_grid(uint16_t pixels[8][8]) {
    for (int y = 0; y < 8; y++) {
        move(y, 0);
        for (int x = 0; x < 8; x++) {
            if (pixels[7 - x][y]) {
                attron(COLOR_PAIR(pixels[7 - x][y]));
                addch('#');
                attroff(COLOR_PAIR(pixels[7 - x][y]));
            } else {
                addch(' ');
            }
        }
    }
    refresh();
}
