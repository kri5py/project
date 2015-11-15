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

/*
* Allocates arrays 
* with atmost n-disks
*/
void initialize (int disks, int peg_A[8], int peg_B[8], int peg_C[8]);

/*
* assigns the number of disks to the variable disks
*/
void get_number_of_disks(int *disks);

/*
* prints the towers on the screen
*/
void print_status(int disks, int peg_A[8], int peg_B[8], int peg_C[8]);

/*
* prints the error message
* if peg with no disks is chosen
*/
void print_no_disk(char *choice_from);

/*
* asks the user to enter the name of the peg 
*  from where a disk will be removed
*  validates input
*/
int validate_move_from(char *choice_from, int peg_A[8], int peg_B[8], int peg_C[8]);

/* asks the user to enter the name of the peg 
*  to which a disk will be placed
*  also validates input
*/
int validate_move_to(int disks, char choice_from, char *choice_to, int *index_from, int peg_A[8], int peg_B[8], int peg_C[8]);

/*
*determines the top  of stack 
*of a certain peg where a disk will be placed
*/
void disk_on_top(int disks, int *top_of_stack_to, char choice_to, int peg_A[8],int peg_B[8], int peg_C[8]);

/*
*moves the chosen disk to the desired peg
*/
void move_disk(int disks, char choice_from, char choice_to, int index_from, int peg_A[8], int peg_B[8], int peg_C[8]);
