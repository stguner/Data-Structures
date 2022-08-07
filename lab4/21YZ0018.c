// Suleyman Turker Guner - 21YZ0018 - LAB4 SOLUTION
// Coded for Data Structures Lecture in Summer School
// 05.08.2022

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "function.h"

int main()
{
	int studentid;
	int midterm;
	int counter;
	while (true) // INPUT FOR STUDENT
	{
		scanf("%d", &studentid);
		if (studentid == -1)
		{
			break;
		}
		else
		{
			scanf("%d", &midterm);
			appendStudent(&head2, studentid, midterm);
		}
	}
	printAll();
	
	return 0;
}
