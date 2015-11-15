/********************************************************
# Copyright (C) 2014, 2015 __MIS 111408005__
# The Application __ TOWER OF HANOI PUZZLE__.
#
# __TOWER OF HANOI PUZZLE__ is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# __TOWER OF HANOI PUZZLE__ is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
********************************************************/

/********************************************************
		TOWER OF HANOI PUZZLE
	    	(With Solutions)

********************************************************/

#include"nprnt.h"

/* solves the puzzzle and 
*prints it using showpegs
*/
void solve_hanoi(peg *p_my_pegs, int n_discs, int src, int aux, int dst) {	

	if(n_discs == 0)
		return;
	solve_hanoi(p_my_pegs, n_discs - 1, src, dst, aux);
	move_disc(p_my_pegs, store_n_discs, src, dst);
	show_pegs(stdscr, p_my_pegs, store_n_discs);
	check_usr_response(p_my_pegs, store_n_discs);
	solve_hanoi(p_my_pegs, n_discs - 1, aux, src, dst);
}

/* checks user response to halt the execution of the code inbetween */
void check_usr_response(peg *p_my_pegs, int n_discs) {	
	int ch;

	ch = getch(); /* Waits for TIME_OUT milliseconds */
	if(ch == ERR)
		return;
	else	
		if(ch == KEY_F(1))
		{	free_pegs(p_my_pegs, n_discs);
			endwin();
			exit(0);
		}
}

/* moves disc 
 */
void move_disc(peg *p_my_pegs, int n_discs, int src, int dst) {	
	int temp, index;
	--p_my_pegs[src].n_discs;
	index = 0;

	while(p_my_pegs[src].sizes[index] == 0 && index != n_discs)
		++index;

	temp = p_my_pegs[src].sizes[index];
	p_my_pegs[src].sizes[index] = 0;
	index = 0;

	while(p_my_pegs[dst].sizes[index] == 0 && index != n_discs)
		++index;

	--index;
	p_my_pegs[dst].sizes[index] = temp;
	++p_my_pegs[dst].n_discs;
}	

/* Allocates arrays 
* with atmost n-disks
*/
void init_pegs(peg *p_my_pegs, int n_discs){
	int size, temp, i;

	p_my_pegs[0].n_discs = n_discs;
	
	/* Allocate memory for size array 		
	 * atmost the number of discs on a peg can be n_discs
 	 */
	for(i = 0; i < n_discs; ++i)	
		p_my_pegs[i].sizes = (int *)calloc(n_discs, sizeof(int));
	size = 3;
	for(i = 0;i < n_discs; ++i, size += 2)
		p_my_pegs[0].sizes[i] = size;

	temp = (p_my_pegs[0].sizes[n_discs - 1] / 2);
 	p_my_pegs[0].bottomx = POSX + 1 + temp;
	p_my_pegs[0].bottomy = POSY + 2 + n_discs;
	
 	p_my_pegs[1].bottomx = p_my_pegs[0].bottomx + 2 + 2 * temp;
	p_my_pegs[1].bottomy = POSY + 2 + n_discs;
	
 	p_my_pegs[2].bottomx = p_my_pegs[1].bottomx + 2 + 2 * temp; 
	p_my_pegs[2].bottomy = POSY + 2 + n_discs;
}	    

/* redraws pegs on the screen
* with minimum size 3x * 
*/
void show_pegs(WINDOW *win, peg *p_my_pegs, int n_discs){
	int i, j;
	int k, x;
	int y, size;
	
	wclear(win);
	attron(A_REVERSE);
	mvprintw(24, 0, "Press F1 to Exit");
	attroff(A_REVERSE);
	for(i = 0;i < 3; ++i)
		mvwprintw(	win, p_my_pegs[i].bottomy - n_discs - 1, 
					p_my_pegs[i].bottomx, "%c", PEG_CHAR);
	y = p_my_pegs[0].bottomy - n_discs;
	for(i = 0; i < 3; ++i)	/* For each peg */
	{	
		for(j = 0; j < n_discs; ++ j)	/* For each row */
		{	
			if(p_my_pegs[i].sizes[j] != 0)
			{	
				size = p_my_pegs[i].sizes[j];
				x = p_my_pegs[i].bottomx - (size / 2);
					for(k = 0; k < size; ++k)
						mvwprintw(win, y, x + k, "%c", DISC_CHAR);
			}
			else	
				mvwprintw(win, y, p_my_pegs[i].bottomx, "%c", PEG_CHAR);
			++y;
		}
		y = p_my_pegs[0].bottomy - n_discs;	
	}
	wrefresh(win);
}

/* deallocates the arrays
*/
void free_pegs(peg *p_my_pegs, int n_discs){
	int i;

	for(i = 0;i < n_discs; ++i)
    		free(p_my_pegs[i].sizes);
}

/* prints the solution in approx middle of the screen
*/
void print_in_middle(int startx, int starty, int width, char *string, WINDOW *win){
	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;

	getyx(win, y, x);

	if(startx != 0)
		x = startx;

	if(starty != 0)
		y = starty;

	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}
