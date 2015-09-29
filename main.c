#include<stdio.h>
#include "TOH2.h"
int main (void)
{       int peg_A[8];   
        int peg_B[8];   
        int peg_C[8];           
        int disks;              
        int index_from;         
        char choice_from;       
        char choice_to;        

        printf("Instructions on playing TOWERS OF HANOI:\nThere are\nthree pegs, labeled A, B, and C.\n\nInitially, peg A contains a certain\namount of disks, each one with a different size.\nThe disks are \nstacked\nin increasing size so that a disk is always on top of a larger one,\nforming a tower.\nThe goal of the game is to move all the disks from peg\nA to peg C.\nYou may move only one disk at a time.\n\nYou may move the\ntop disk from any peg to the top of the stack at another peg.\nThe\nonly\nlimitation is that you may not place a disk on top of one which is\nsmaller.\nYOU MAY STOP THE GAME ANYTIME BY ENTERING Q (THEN PRESSING \nTHE\nENTER KEY)");
        get_number_of_disks(&disks);
        initialize(disks, peg_A, peg_B, peg_C);
        print_status(disks, peg_A, peg_B, peg_C);
        while (peg_C[disks-1]!=3)
        {       validate_move_from(&choice_from, peg_A, peg_B, peg_C);
                if(choice_from=='Q' || choice_from=='q')
                        break;
                validate_move_to(disks, choice_from, &choice_to,&index_from, peg_A, peg_B, peg_C);
                if(choice_to=='Q' || choice_to=='q')
                        break;
                move_disk(disks, choice_from, choice_to, index_from,peg_A, peg_B, peg_C);
                print_status(disks, peg_A, peg_B, peg_C); }
        if(peg_C[disks-1]==3)
                printf("Congratulations! You won!\n");
	/*else {
	*while(scanf(n) != EOF ) {	
	*soln(	
	*printf(" press N to get the solution" );
	*-- print the solution -----
	*}	
	*}
	*/
        return 0; }
 
