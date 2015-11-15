#include<stdio.h>
#include "TOH2.h"



void initialize (int disks, int peg_A[8], int peg_B[8], int peg_C[8])
{       int i;
        for(i=0; i<disks; i++)
        {       peg_A[i]=(disks-i)*2 + 1;
                peg_B[i]=1;
                peg_C[i]=1;
	}
}


void get_number_of_disks(int *disks)
{       printf("Enter the number of disks(min of 3, max of 8): ");
        scanf("%d", disks);
        while(*disks>8 || *disks<3)
        {       printf("Invalid input!\nEnter the number of\ndisks(min of 3, max of 8): ");
                scanf("%d", disks); 
	}
}


void print_status(int disks, int peg_A[8], int peg_B[8], int peg_C[8])
{       int number_spaces;        
        int number_asterisk;      
        int i=1;                  
        printf("\n");
        for(i=1; i<=disks; i++)
        {       for(number_spaces=1; number_spaces<=(disks+3)-(peg_A[disks-i]/2); number_spaces++)
                        printf(" ");
                for(number_asterisk=1; number_asterisk <= peg_A[disks-i];number_asterisk++)
                        printf("*");
                for(number_spaces=1; number_spaces<=(disks+3)-(peg_A[disks-i]/2); number_spaces++)
                        printf(" ");
                for(number_spaces=1; number_spaces<=(disks+3)-(peg_B[disks-i]/2); number_spaces++)
                        printf(" ");
                for(number_asterisk=1; number_asterisk <= peg_B[disks-i];number_asterisk++)
                        printf("*");
                for(number_spaces=1; number_spaces<=(disks+3)-(peg_B[disks-i]/2); number_spaces++)
                        printf(" ");
                for(number_spaces=1; number_spaces<=(disks+3)-(peg_C[disks-i]/2); number_spaces++)
                        printf(" ");
                for(number_asterisk=1; number_asterisk <= peg_C[disks-i];number_asterisk++)
                        printf("*");
                printf("\n");}
        for(i=1; i<=(disks*2 + 7)*3; i++)
                printf("#");
        printf("\n");
        for(i=1; i<=disks+3; i++)
                printf(" ");
        printf("A");
        for(i=1; i<=(disks + 3)*2; i++)
                printf(" ");
        printf("B");
        for(i=1; i<=(disks + 3)*2; i++)
                printf(" ");
        printf("C\n\n"); }


void print_no_disk(char *choice_from)
{       printf("There's no disk!\nChoose a peg with disk(s).\nMove a disk\nfrom what peg?: ");
        scanf("%s", choice_from); 
}


int validate_move_from(char *choice_from, int peg_A[8], int peg_B[8], int peg_C[8])
{       printf("Move a disk FROM what peg?: ");
        scanf("%c", choice_from);
        if (*choice_from=='Q' || *choice_from=='q')
                return 0;
        while(peg_A[0] == 1 && (*choice_from == 'A' || *choice_from =='a'))
                print_no_disk(choice_from);
        while(peg_B[0] == 1 && (*choice_from == 'B' || *choice_from =='b'))
                print_no_disk(choice_from);
        while(peg_C[0] == 1 && (*choice_from == 'C' || *choice_from =='c'))
                print_no_disk(choice_from);
        while(*choice_from<'A' || (*choice_from>'C' && *choice_from<'a') || *choice_from>'c')
                {printf("(A, B, C or Q only): ");
                scanf("%c", choice_from);
                if (*choice_from=='Q' || *choice_from=='q')
                        return 0;
                while(peg_A[0] == 1 && (*choice_from == 'A' || *choice_from =='a'))
                        print_no_disk(choice_from);
                while(peg_B[0] == 1 && (*choice_from == 'B' || *choice_from =='b'))
                        print_no_disk(choice_from);
                while(peg_C[0] == 1 && (*choice_from == 'C' || *choice_from =='c'))
                        print_no_disk(choice_from); }
        return 0;
}


int validate_move_to(int disks, char choice_from, char *choice_to, int *index_from, int peg_A[8], int peg_B[8], int peg_C[8])
{       int i;
        int top_of_stack_from,        /* disk to be removed*/
        top_of_stack_to;              /*smallest */
        for (i=disks-1; i>=0; i--)
        {        if ((choice_from=='A' || choice_from=='a') && peg_A[i]!=1)
                {       top_of_stack_from = peg_A[i];
                        *index_from=i;
                        break; }
                else if ((choice_from=='B' || choice_from=='b') && peg_B[i]!=1)
                {       top_of_stack_from = peg_B[i];
                        *index_from=i;
                        break; 
		}
                else if ((choice_from=='C' || choice_from=='c') && peg_C[i]!=1)
                {       top_of_stack_from = peg_C[i];
                        *index_from=i;
                        break; }}
        printf("Move the disk TO: ");
        scanf("%c", choice_to);
        if (*choice_to=='Q' || *choice_to=='q')
                return 0;
        disk_on_top(disks, &top_of_stack_to, *choice_to, peg_A, peg_B,
peg_C);
        while(*choice_to<'A' || (*choice_to>'C' && *choice_to<'a') ||
*choice_to>'c')
        {       printf("(A, B, or C only): ");
                scanf("%c", choice_to);
        if (*choice_to=='Q' || *choice_to=='q')
                return 0;
        disk_on_top(disks, &top_of_stack_to, *choice_to, peg_A, peg_B,
peg_C); }
        while(top_of_stack_to-top_of_stack_from<0)
        {       printf("That is an INVALID move!\nChoose a peg with a\nlarger disk.\nMove the disk TO: ");
                scanf("%c", choice_to);
                if (*choice_to=='Q' || *choice_to=='q')
                        return 0;
                while(*choice_to<'A' || (*choice_to>'C' && *choice_to<'a') || *choice_to>'c')
                {       printf("(A, B, or C only): ");
                        scanf("%c", choice_to);
                        if (*choice_to=='Q' || *choice_to=='q')
                                return 0;
                        disk_on_top(disks, &top_of_stack_to, *choice_to,peg_A, peg_B, peg_C); }}
        return 0; }


void disk_on_top(int disks, int *top_of_stack_to, char choice_to, int peg_A[8],int peg_B[8], int peg_C[8])
{       int i;
        for (i=disks-1; i>=0; i--)
        {        if ((choice_to=='A' || choice_to=='a') && peg_A[i]!=1)
                {        *top_of_stack_to = peg_A[i];
                        break; 
		}
                else if ((choice_to=='B' || choice_to=='b') && peg_B[i]!=1)
                {        *top_of_stack_to = peg_B[i];
                        break; 
		}
                else if ((choice_to=='C' || choice_to=='c') && peg_C[i]!=1)
                {        
			*top_of_stack_to = peg_C[i];
                        break; }
                else     *top_of_stack_to=17; }}


void move_disk(int disks, char choice_from, char choice_to, int
index_from, int peg_A[8], int peg_B[8], int peg_C[8])
{       int i, temp, index_to;
        for (i=0; i<disks; i++)
        {       if ((choice_to=='A' || choice_to=='a') && peg_A[i]==1)
                {        index_to=i;
                        break; }
                else if ((choice_to=='B' || choice_to=='b') && peg_B[i]==1)
                {        index_to=i;
                        break; }
                else if ((choice_to=='C' || choice_to=='c') && peg_C[i]==1)
                {        index_to=i;
                        break; }}
        if ((choice_from=='A' || choice_from=='a') && (choice_to=='B' || choice_to=='b'))
        {       temp = peg_B[index_to];
                peg_B[index_to] = peg_A[index_from];
                peg_A[index_from] = temp; }
        else if ((choice_from=='A' || choice_from=='a') && (choice_to=='C'|| choice_to=='c'))
        {       temp = peg_C[index_to];
                peg_C[index_to] = peg_A[index_from];
                peg_A[index_from] = temp; }
        else if ((choice_from=='B' || choice_from=='b') && 
(choice_to=='C' || choice_to=='c'))
        {       temp = peg_C[index_to];
                peg_C[index_to] = peg_B[index_from];
                peg_B[index_from] = temp; }
        else if ((choice_from=='B' || choice_from=='b') && 
(choice_to=='A'|| choice_to=='a'))
        {       temp = peg_A[index_to];
                peg_A[index_to] = peg_B[index_from];
                peg_B[index_from] = temp; }
        else if ((choice_from=='C' || choice_from=='c') && 
(choice_to=='A'|| choice_to=='a'))
        {       temp = peg_A[index_to];
                peg_A[index_to] = peg_C[index_from];
                peg_C[index_from] = temp; }
        else if ((choice_from=='C' || choice_from=='c') && 
(choice_to=='B'||choice_to=='b'))
        {       temp = peg_B[index_to];
                peg_B[index_to] = peg_C[index_from];
                peg_C[index_from] = temp;
 }
}
	
