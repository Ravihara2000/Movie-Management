#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "w.h"


int main()
{
	int opt, findan, seret;
	
	seriesPtr stPtr = NULL;
	
	int d = 0, u = 4;
	
	fileread();
	
	showmenu();
	
	printf("\nEnter your Option   :");
	scanf("%d",&opt);
	
	do
	{
		switch(opt)
		{
			case 1: display();
			printf("\n");break;
			
			case 2:
			printf("1. Sort the list according to Ascending order \n");
			printf("2. Sort the list according to Descending order \n");
			printf("\n Enter your option  :");
			scanf("%d", &opt);
			
			
			if(opt == 1)
			{
				Insesort();
				printf("Sorted the list Ascending order \n");
				printf("List is sorted by using Insertion sort \n");
				display();
			}
			else if(opt == 2)
			{
				Bubbsort();
				printf("Sorted he list Descending order \n");
				printf("List is sorted by using Bubble sort \n");
				display();
			}
			else
			{
				printf("You enterd Invalid option \n\n");
			printf("\n");break;
			}
			
			case 3:
			printf("Search the TV Series in Linear method\n");
			printf("Search the TV Series in Binary method \n");
			
			printf("\nEnter your option  :");
			scanf("%d", &opt);
			
			
			if(opt == 1)
			{
				display();
				
				printf("\nEnter TV Series ID to search  :");
				scanf("%d", &findan);
				
				seret = Linsearch(findan);
				
				if(seret != -1)
				{
					printf("--Found the details-- \n");
					printf("%s\t %s\t %s\n", fname, sname, tname);
					printf("%-20s%-15d%.2f\n", s[seret].series_name, s[seret].ID, s[seret].IMDB);
				}
				else
					printf("--Details are not found-- \n");
			}
			else if(opt == 2)
			{
				Insesort();
				
				display();
				
				printf("\n Enter TV Series ID to search  :");
				scanf("%d", &findan);
				
				seret = binsearch(findan, d, u);
				
				if(seret != -1)
				{
					printf("--Details found-- \n");
					printf("%s\t%s\t%s\n", fname, sname, tname);
					printf("%-20s%-15d%.2f\n", s[seret].series_name, s[seret].ID,s[seret].IMDB);
					
				}
				else
					printf("--Details not found--\n");
				
				fflush(stdin);
			}
			else
				printf("--You entered invalid input--");
			
			printf("\n");break;
			
			case 4:
			
			printf("Insearting \n");
			
			for(int i = 0; i < arr; i++)
			{
				//takeinput(&stPtr, s[i].series_name, s[i].ID, s[i].IMDB);
			}
			
			//showLinkedList(stPtr);
			printf("\n");
			break;
			
			case 5:
			
			exit(0);
			
			default :
			
			printf("You entered Invalid option\n\n");
			break;
			
			
			
			
		}
		showmenu();
		printf("\n Enter your option  :");
		scanf("%d", &opt);
		
	}while(opt != 5);
	
	return 0;

}

void showmenu()
{
	printf("1. Display the List \n");
	printf("2. Sort the List\n");
	printf("3. Search the item from list\n");
	printf("4. Insert inputs to the linked List\n");
	printf("5. Quit");
}

void fileread()
{
	FILE *fp;
	
	fp = fopen("q1.txt", "r");
	
	fscanf(fp," %s\t%s\t%s", fname, sname,tname);
	
	for(int i = 0; i < 5; i++)
	{
		fscanf(fp, "%s\t\t%d\t\t%f" ,s[i].series_name, &s[i].ID, &s[i].IMDB);
	}
	
	fclose(fp);
}

void display()
{
	printf("%s\t%s\t%s\n",fname, sname, tname);
	
	for(int i = 0; i < 5; i++)
	{
		printf("%-20s%-15d%.2f\n",s[i].series_name, s[i].ID, s[i].IMDB);
	}

}

void Insesort()
{
	int x, y;
	
	series in;
	
	for(x = 1; x < arr; ++x)
	{
		in = s[x];
		
		for(y = x; y > 0 && s[y-1].ID > in.ID; y--)
			s[y] = s[y-1];
		
		s[y] = in;
	}

	fileDis();
}

void Bubbsort()
{
	int x, y;
	series te;
	
	
	for(x = 0; x < (arr - 1); ++x)
	{
		for(y = 0; y < arr -1 - x; ++y)
		{
			if(s[y].ID < s[y+1].ID)
			{
				te = s[y+1];
				s[y+1] = s[y];
				s[y] = te;
			}
		}
		
	}
	fileDis();
}

void fileDis()
{
	FILE *fp;
	
	fp = fopen("text.txt", "w");
	
	fprintf(fp, "%s\t%s\t%s\n", fname, sname, tname);
	
	for(int i = 0; i < 5; i++)
	{
		fprintf(fp, "%-20s%-15d%.2f\n", s[i].series_name, s[i].ID, s[i].IMDB);
	}
	fclose(fp);
}
int Linsearch(int finum)
{
	int i;
	
	for(i = 0; i < arr; i++)
	{
		if(s[i].ID == finum)
			return i;
	}
	return -1;
}

int binsearch(int finum, int d, int u)
{
	int cen = 0;
	
	while(d <= u)
	{
		cen = (d + u)/2;
		if(finum == s[cen].ID)
		{
			return cen;
		}
		else if (finum < s[cen].ID)
		{
			u = cen - 1;
		}
		else
		{
			d = cen +1;
		}
	}
	return -1;
}



void takeinput(seriesPtr *sPtr, char Name[25], int id, float value)
{
	seriesPtr nPtr;
	seriesPtr prePtr;
	seriesPtr curPtr;
	
	nPtr = malloc(sizeof(series));
	
	if(nPtr != NULL)
	{
		strcpy(nPtr->series_name, Name);
		nPtr->ID = id;
		nPtr->IMDB = value;
		nPtr->next = NULL;
		prePtr = NULL;
		curPtr = *sPtr;
		
		while(curPtr != NULL && id > curPtr->ID)
		{
			prePtr = curPtr;
			curPtr = curPtr->next;
			
		}
		if(prePtr == NULL)
		{
			nPtr->next = *sPtr;
			*sPtr = nPtr;
		}
		else
		{
			prePtr->next = nPtr;
			nPtr->next = curPtr;
		}
	}
}


void showLinkedList(seriesPtr sPtr)
{
	printf("%s\t%s\t%s\n", fname, sname, tname);
	while(sPtr != NULL)
	{
		printf("%-20s%-15d%.2f\n", sPtr->series_name, sPtr->ID, sPtr->IMDB);
		sPtr = sPtr-> next;
	}
}

