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

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
* Declarations of three stacks representing the towers
* and their tops 
*/
int p1[100],p2[100],p3[100],top1=0,top2=0,top3=0;

/*
* pushes the given disk on tower 'a'
*/
void pushp1(int a)
{
	if(a!=0)
	p1[top1++]=a;
}

/*
* pops the disk on top from tower 'a'
*/
int popp1(void)
{
	if(top1==0)
		return 0;
	else
		return p1[--top1];
}

/*
* displays the content of tower 'a'
*/
void displayp1(void)
{
	int i;
	printf("Tower 1 ->> ");
	if(top1==0)
		printf("NULL");
	else
	for(i=0;i<top1;i++)
	{
		printf("%d ",p1[i]);
	}
	printf("\n");
}

/*
* pushes the given disk on tower 'b'
*/
void pushp2(int a)
{
	if(a!=0)
	p2[top2++]=a;
}

/*
* pops the disk on top from tower 'b'
*/
int popp2(void)
{
	if(top2==0)
		return 0;
	else
		return p2[--top2];
}

/*
* displays the content of tower 'b'
*/
void displayp2(void)
{
	int i;
	printf("Tower 2->> ");
	if(top2==0)
		printf("NULL");
	else
	for(i=0;i<top2;i++)
	{
		printf("%d ",p2[i]);
	}
	printf("\n");
}

/*
* pushes the given disk on tower 'c'
*/
void pushp3(int a)
{
	if(a!=0)
	p3[top3++]=a;
}

/*
* pops the disk on top from tower 'c'
*/
int popp3(void)
{
	if(top3==0)
		return 0;
	else
		return p3[--top3];
}

/*
*  displays the content of tower 'c'
*/
void displayp3(void)
{
	int i;
	printf("Tower 3 ->> ");
	if(top3==0)
		printf("NULL");
	else
	for(i=0;i<top3;i++)
	{	
		printf("%d ",p3[i]);
	}
	printf("\n");
}

/*
* prints the towers 
* and the solution
* by redrawing the structure after every move
*/
int printsoln(int n){
	int i,x,a,b;
	for(i=0;i<n;i++)
	pushp1(n-i);
	x=pow(2,n)-1;
	displayp1();
	displayp2();
	displayp3();
	for(i=1;i<=x;i++)
	{
		if(i%3==1)
		{
		a=popp1();
		b=popp3();
		if(a==0)
			{
				pushp1(b);
			}
			else
				if(b==0)
				pushp3(a);
			else
				if(a>b)
			{
				pushp1(a);
				pushp1(b);
			}
			else
			{
				pushp3(b);
				pushp3(a);
			}
			displayp1();
			displayp2();
			displayp3();
			continue;
		}
		else
		if(i%3==2)
		{
			a=popp1();
			b=popp2();
			if(a==0)
			{
				pushp1(b);
			}
			else
				if(b==0)
				pushp2(a);
			else
				if(a>b)
			{
				pushp1(a);
				pushp1(b);
			}
			else
			{
				pushp2(b);
				pushp2(a);
			}
			displayp1();
			displayp2();
			displayp3();
			continue;
		}
		else
		if(i%3==0)
		{
		a=popp2();
		b=popp3();
		if(a==0)
			{
				pushp2(b);
			}
			else
				if(b==0)
				pushp3(a);
			else
				if(a>b)
			{
				pushp2(a);
				pushp2(b);
			}
			else
			{
				pushp3(b);
				pushp3(a);
			}
			displayp1();
			displayp2();
			displayp3();
			continue;
		}   
	}
	printf("Complete\n");
	displayp1();
	displayp2();
	displayp3();
return 0;
}

