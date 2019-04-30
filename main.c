#include <stdio.h>
#include <stdlib.h>

int animal(int year);
int leapyear(int year);
int Calendar (int year, int month, int leap);
int Space (int year, int month, int day);

int main()
{
	int year,month,leap;
	printf("Which year?\n");
	scanf("%d",&year);
	printf("Which month?\n");
	scanf("%d",&month);
	animal(year);
	leap=leapyear(year);
	if(leap==1)
    {
       	printf("%d is leap year",year);
    }
    else
    {
        printf("%d is not leap year",year);
    }
	printf("\n------------ %d / %d ------------\n\n", year, month);
	Calendar(year,month,leap);
	return 0;
}
int animal(int year)
{
	int leftover=(year+9)%12;
	if (leftover==1)
	{
		printf("%4d-> MOUSE\n", year);
	}
	else if (leftover==2)
	{
		printf("%4d -> COW\n", year);
	}
	else if (leftover==3)
	{
		printf("%4d -> TIGER\n", year);
	}
	else if (leftover==4)
	{
		printf("%4d -> RABBIT\n", year);
	}
	else if (leftover==5)
	{
		printf("%4d -> DRAGON\n", year);
	}
	else if (leftover==6)
	{
		printf("%4d -> SNAKE\n", year);
	}
	else if (leftover==7)
	{
		printf("%4d -> HORSE\n", year);
	}
	else if (leftover==8)
	{
		printf("%4d -> SHEEP\n", year);
	}
	else if (leftover==9)
	{
		printf("%4d -> MONKEY\n", year);
	}
	else if (leftover==10)
	{
		printf("%4d -> COOK\n", year);
	}
	else if (leftover==11)
	{
		printf("%4d -> DOG\n", year);
	}
	else if (leftover==12)
	{
		printf("%4d -> BOAR\n", year);
	}
	return;
}

int leapyear(int year)
{
	if ((year % 4 == 0) && (year % 100 !=0))
		return 1;
	else if (year % 400 == 0)
		return 1;
	else
		return 0;
}

int Calendar (int year, int month, int leap)
{
	int space,space2,i;
	space=Space(year,month,1);
	space2=space;
	char dayofw[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int lastdate[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (i = 0;i < 7;i = i + 1)
	{
		printf(" %s ", dayofw[i]);
	}
	printf("\n");
	for (i = 0;i < space;i = i + 1)
    {
    	printf("     ");
    }
	if ((leap == 1) && (month == 2))
	{
		for (i = 1;i <= 29;i = i + 1)
		{
			printf(" %02d  ", i);
			space2 = space2 + 1;
			if (space2 == 7)
			{
				printf("\n");
				space2 = 0;
			}
		}
	} 
	else
	{
		for (i = 1; i <= lastdate[month-1];i = i + 1)
		{
			printf(" %02d  ", i);
			space2 = space2 + 1;
			if (space2 == 7)
			{
				printf("\n");
				space2 = 0;
			}
		}
	}
	printf("\n");
	return;
}


int Space (int year, int month, int day)
{
	int space2,space;
	if (month < 3)
	{
		month = month + 12;
		year = year - 1;
	}
	space2 = (year + (year / 4) - (year / 100) + (year / 400) + (2.6 * month + 1.6) + day);
	space = (space2)%7;
	return space;
}
