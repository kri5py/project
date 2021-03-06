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

#include <stdlib.h>
#include <string.h>

#include <curses.h>

#define POSX 10
#define POSY 5
#define DISC_CHAR '*'
#define PEG_CHAR '*'
#define TIME_OUT 300

typedef struct _peg_struct {
	int n_discs;		/* Number of discs at present 	*/
	int bottomx, bottomy;	/* bottom x, bottom y co-ord  	*/
	int *sizes;		/* The disc sizes array		*/
}peg;

/* 
* Allocates arrays 
* with atmost n-disks
*/
void init_pegs(peg *p_my_pegs, int n_discs);

/*
* redraws pegs on the screen
* with minimum size 3x * 
*/
void show_pegs(WINDOW *win, peg *p_my_pegs, int n_discs);

/*
* deallocates the arrays
*/
void free_pegs(peg *p_my_pegs, int n_discs);

/*
* solves the puzzzle and 
* prints it using showpegs
*/
void solve_hanoi(peg *p_my_pegs, int n, int src, int aux, int dst);

/*
* moves disc 
*/
void move_disc(peg *p_my_pegs, int n_discs, int src, int dst);

/*
* prints the solution in approx middle of the screen
*/
void print_in_middle(int startx, int starty, int width, char *string, WINDOW *win);

/*
* checks user response to halt the execution of the code inbetween 
*/
void check_usr_response(peg *p_my_pegs, int n_discs); 

int store_n_discs;

