#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

#define WHITE 1
#define BLACK 0

void draw_grid(uint16_t pixels[8][8]) {
    for(int y=0; y<8; y++) {
        move(y,0);
        for(int x=0; x<8; x++) {
            if(pixels[7-x][y]) {
                attron(COLOR_PAIR(pixels[7-x][y]));
                addch('#');
                attroff(COLOR_PAIR(pixels[7-x][y]));
            } else {
                addch(' ');
            }
        }
    }
    refresh();
}

void fill_pixels(uint16_t pixels[8][8], uint16_t color) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            pixels[i][j] = color;
        }
    }
}

int main(void) {
    // uint16_t means "non-negative two-byte integer"
    uint16_t pixel[8][8];

    // Starts drawing in the terminal
    initscr();
    start_color();
    /* This means consider WHITE to mean 
     * foreground is COLOR_WHITE (i.e., white) and
     * background is also COLOR_WHITE.
     * The value of WHITE was #defined above.
     * The value of COLOR_WHITE is #defined in 
     * ncurses.h. You can also use:
     * COLOR_BLACK
     * COLOR_RED
     * COLOR_GREEN
     * COLOR_YELLOW
     * COLOR_BLUE
     * COLOR_MAGENTA
     * COLOR_CYAN
     * but you probably also want to define your own, for example
     * #define RED 2
     */
    #define RED 2
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(RED, COLOR_RED, COLOR_RED);

    fill_pixels(pixel,BLACK);
    // Top of J
    pixel[1][0]=RED;
    pixel[2][0]=RED;
    pixel[3][0]=RED;
    pixel[4][0]=RED;
    pixel[5][0]=RED;
    pixel[6][0]=RED;

   // Middle
    pixel[3][1]=RED;
    pixel[3][2]=RED;
    pixel[3][3]=RED;
    pixel[3][4]=RED;
    pixel[3][5]=RED;
    pixel[3][6]=RED;
    pixel[7][6]=RED;
    pixel[4][1]=RED;
    pixel[4][2]=RED;
    pixel[4][3]=RED;
    pixel[4][4]=RED;
    pixel[4][5]=RED;
    pixel[4][6]=RED;

   // Bottom of J
    pixel[7][7]=RED;
    pixel[6][7]=RED;
    pixel[5][7]=RED;
    pixel[4][7]=RED;
    pixel[3][7]=RED;

   // see: man 3 sleep
    draw_grid(pixel);
    sleep(2);
     fill_pixels(pixel,BLACK);
   // Top of C
    pixel[3][0]=WHITE;
    pixel[4][0]=WHITE;
    pixel[5][0]=WHITE;
    pixel[6][0]=WHITE;
    pixel[2][0]=WHITE;
    pixel[1][0]=WHITE;
 
   // Middle
    pixel[6][6]=WHITE;
    pixel[6][5]=WHITE;
    pixel[6][4]=WHITE;
    pixel[6][3]=WHITE;
    pixel[6][2]=WHITE;
    pixel[6][1]=WHITE;
    pixel[5][6]=WHITE;
    pixel[5][5]=WHITE;
    pixel[5][4]=WHITE;
    pixel[5][3]=WHITE;
    pixel[5][2]=WHITE;
    pixel[5][1]=WHITE;
   // Bottom of C
    pixel[5][7]=WHITE;
    pixel[4][7]=WHITE;
    pixel[3][7]=WHITE;
    pixel[6][7]=WHITE;
    pixel[2][7]=WHITE;
    pixel[1][7]=WHITE;
   // see: man 3 sleep
    draw_grid(pixel);
    sleep(2);
    // endwin() should only be called once/program
    endwin();
    return 0;
}
