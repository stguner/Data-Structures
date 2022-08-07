// Suleyman Turker Guner - 21YZ0018 - LAB3 SOLUTION
// Coded for Data Structures Lecture in Summer School
// 02.08.2022

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "function.h"

int main()
{
	int gsid;
	int fbAge;
	int fbid;
	int counter;

	while (true) // INPUT FOR FB
	{	
		scanf("%d", &fbid);
		if (fbid == -1)
		{
			break;
		}
		else
		{
			counter++;
			scanf("%d", &fbAge);
			appendFB(&head2, fbid, fbAge);
		}
	}
	
	printf("\n");

	while (true) // INPUT FOR GS
	{
		scanf("%d", &gsid);
		if (gsid == -1)
		{
			break;
		}
		appendGS(&head, gsid);
	}

	printf("\n");

	descendingSortListGS();
	ascendingSortListFB();
	printListFB(head2);
	printListGS(head);

	printf("\n");
	for (int i = 1; i < counter * 2; i++)
	{
		printElementFB(head2,i);
		printElementGS(head,i);
	}
	

	return 0;
}
