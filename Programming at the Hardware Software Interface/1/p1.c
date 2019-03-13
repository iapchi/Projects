/*
Jacky Li
*/
//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Main Function
int main()
{
	//Declaring variables
	int sday;	//Declaraction of integer variable to hold startday
	int smonth;	//Declaraction of integer variable to hold startmonth
	int eday;	//Declaraction of integer variable to hold endday
	int emonth;	//Declaraction of integer variable to hold endmonth
	//Set month array
	int monthdays[12]={31,29,31,30,31,30,31,31,30,31,30,31};

	//Loop to stop executing only if user enters an invalid date
	while(1)
	{
		//Declaring variables
		int m1 = 0;
		int d1 = 0;
		int m2 = 0;
		int d2 = 0;
		int days_of_month = 0;
		int answer = 0;

		//Get's starting date from user
		printf("\nStart Date :");fflush(stdout);
		//Reading month
		scanf("%d",&smonth);
		//Reading day
		scanf("%d",&sday);

		//Check if start month is not in the valid range of January -  December
		if(smonth < 1 || smonth > 12)
		{
			printf("\n!!!!Date is Invalid!!!!");fflush(stdout);
			printf("\n~~ Closing Program ~~");fflush(stdout);
			break;
		}
		else
		{
			m1 = smonth;
			d1 = monthdays[m1 - 1];
			if(sday < 1 || sday > d1)
			{
				printf("\n!!!!Date is Invalid!!!!");fflush(stdout);
				printf("\n~~ Closing Program ~~");fflush(stdout);
				break;
			}
		}
		//Get's ending date from user
		printf("\nEnd Date :");fflush(stdout);
		//Reading month
		scanf("%d",&emonth);
		scanf("%d",&eday);

		//Check if end month is not in the valid range of January -  December
		if(emonth < 1 || emonth > 12)
		{
			printf("\n!!!!Date is Invalid!!!!");fflush(stdout);
			printf("\n~~ Closing Program ~~");fflush(stdout);
			break;
		}
		else
		{
			m2 = emonth;
			d2 = monthdays[m2 -1];
			if(eday < 1 || eday > d2)
			{
				printf("\n!!!!Date is Invalid!!!!");fflush(stdout);
				printf("\n~~ Closing Program ~~");fflush(stdout);
				break;
			}
		}

		//Check if end month is greater than start month
		if(m2 < m1)
		{
			printf("\n !!!! End Date must be greater than Start Date !!!!");fflush(stdout);
			printf("\n~~ Closing Program ~~");fflush(stdout);
			break;
		}
		//Check if dates are positive
		else if (m2 == m1 && ((monthdays[m2 - 1]-(eday - 1)) - ((monthdays[m1 - 1]) - sday) < 0))
		{
			printf("\nError");fflush(stdout);
			printf("\n~~ Closing Program ~~");fflush(stdout);
			break;
		}
		//Check if dates are the same
		else if (m2 == m1 && sday == eday)
		{
			printf("\nSame date, %d days in between",eday-sday);fflush(stdout);
		}
		//Calculate days inbetween if dates are in same month
		else if(m2 == m1 && sday < eday)
		{
			printf("\nNumber of days between two dates is %d ",eday-sday);fflush(stdout);
			continue;
		}
		//Calculates the days inbetween if dates are in different months
		else
		{
			int i;
			for(i = m1;i < m2 - 1;i++)
			{
				days_of_month = days_of_month + monthdays[i - 1];
			}
			answer = (monthdays[m1-1] - sday)+days_of_month + (eday-1);
			printf("\nNumber of days between two dates is %d ",answer);fflush(stdout);
			continue;
		}
	}
	return 0;
}
