#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include "display.h"

int main(){
    open_display();
    while (1) {

    int hours, minutes, seconds;
    if (scanf("%d:%d:%d",&hours,&minutes,&seconds) != 3) {
            break;
            }
    clear();
    display_time(hours,minutes,seconds);
    refresh();
    }
close_display();
    return 0;
}
