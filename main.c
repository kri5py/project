#include<stdio.h>
#include "TOH2.h"
#include"nprnt.h"
#include <curses.h>
char *welcome_string = "Enter the number of discs you want to be solved: ";
int main (void)
{       int peg_A[8];   
        int peg_B[8];   
        int peg_C[8];            
        int disks;
	int choice;              
        int index_from;         
        char choice_from;       
        char choice_to;        

	int n_discs;
	peg my_pegs[3];

        printf("Instructions on playing TOWERS OF HANOI:\nThere are\nthree pegs, labeled A, B, and C.\n\nInitially, peg A contains a certain\namount of disks, each one with a different size.\nThe disks are \nstacked\nin increasing size so that a disk is always on top of a larger one,\nforming a tower.\nThe goal of the game is to move all the disks from peg\nA to peg C.\nYou may move only one disk at a time.\n\nYou may move the\ntop disk from any peg to the top of the stack at another peg.\nThe\nonly\nlimitation is that you may not place a disk on top of one which is\nsmaller.\nYOU MAY STOP THE GAME ANYTIME BY ENTERING Q (THEN PRESSING \nTHE\nENTER KEY)");
        get_number_of_disks(&disks);
        initialize(disks, peg_A, peg_B, peg_C);
        print_status(disks, peg_A, peg_B, peg_C);
        while (peg_C[disks-1]!=3)
        {       validate_move_from(&choice_from, peg_A, peg_B, peg_C);
                if(choice_from=='Q' || choice_from=='q')
                       {
			printf("1.print sol'n\n");
			//sleep(10);			
			printf("2.Display sol'n\n");                       
			printf("3.Exit\n");
			scanf("%d",&choice);
			switch(choice) {
			case 1:
				printsoln(disks);   
				break;
			case 2:
					initscr();	/* Start curses mode 		*/
					cbreak();	/* Line buffering disabled. Pass on every thing */
					keypad(stdscr, TRUE);
					curs_set(FALSE);
	
					print_in_middle(0, LINES / 2, COLS, welcome_string, NULL);
					scanw("%d", &n_discs);	

					timeout(TIME_OUT);
					noecho();
					store_n_discs = n_discs;

					init_pegs(my_pegs, n_discs);
					show_pegs(stdscr, my_pegs, n_discs);
					solve_hanoi(my_pegs, n_discs, 0, 1, 2);

					free_pegs(my_pegs, n_discs);
					endwin();		/* End curses mode		  */
					break;
			case 3:
				break;

			
			}
			break;
		
		}
 
                validate_move_to(disks, choice_from, &choice_to,&index_from, peg_A, peg_B, peg_C);
                if(choice_to=='Q' || choice_to=='q') {
			printf("1.print sol'n\n");
			//sleep(10);			
			printf("2.Display sol'n\n");                       
			printf("3.Exit\n");
			scanf("%d",&choice);
			switch(choice) {
			case 1:
				printsoln(disks);   
				break;
			case 2:
					initscr();	/* Start curses mode 		*/
					cbreak();	/* Line buffering disabled. Pass on every thing */
					keypad(stdscr, TRUE);
					curs_set(FALSE);
	
					print_in_middle(0, LINES / 2, COLS, welcome_string, NULL);
					scanw("%d", &n_discs);	

					timeout(TIME_OUT);
					noecho();
					store_n_discs = n_discs;

					init_pegs(my_pegs, n_discs);
					show_pegs(stdscr, my_pegs, n_discs);
					solve_hanoi(my_pegs, n_discs, 0, 1, 2);

					free_pegs(my_pegs, n_discs);
					endwin();		/* End curses mode		  */
					break;
			case 3:
				break;

			
			}
			break;
		
		}
                move_disk(disks, choice_from, choice_to, index_from,peg_A, peg_B, peg_C);
                print_status(disks, peg_A, peg_B, peg_C); }
        if(peg_C[disks-1]==3)
                printf("Congratulations! You won!\n");
	
        return 0; }
 
