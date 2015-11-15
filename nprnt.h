#include <stdlib.h>
#include <string.h>

#include <curses.h>

#define POSX 10
#define POSY 5
#define DISC_CHAR '*'
#define PEG_CHAR '#'
#define TIME_OUT 300

typedef struct _peg_struct {
	int n_discs;		/* Number of discs at present 	*/
	int bottomx, bottomy;	/* bottom x, bottom y co-ord  	*/
	int *sizes;		/* The disc sizes array		*/
}peg;

void init_pegs(peg *p_my_pegs, int n_discs);
void show_pegs(WINDOW *win, peg *p_my_pegs, int n_discs);
void free_pegs(peg *p_my_pegs, int n_discs);
void solve_hanoi(peg *p_my_pegs, int n, int src, int aux, int dst);
void move_disc(peg *p_my_pegs, int n_discs, int src, int dst);
void print_in_middle(int startx, int starty, int width, char *string, WINDOW *win);
void check_usr_response(peg *p_my_pegs, int n_discs);

int store_n_discs;
