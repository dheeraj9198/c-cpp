#include <stdio.h>
#include <iostream>
#include<map>
using namespace std;
class Day 
{
	public :
	long ageOfConsistent;
	long numTrophyWon;
};

int main()
{


	long numDays;
	long numGhosts;

	long currentDayWinnerAge;

	Day oldDay;
	Day tempDay;

	scanf("%ld",&numDays);
	scanf("%ld",&numGhosts);

	std::map <int, int> ageToWinMap;

/*
	long ghostsArrayTrophy[numGhosts+1];

	long y = 0;
	for(long k = 0; k<numGhosts+1;k++)
	{
		ghostsArrayTrophy[k] = 0;
	}
	*/

/*
	for(long k = 0; k<numGhosts+1;k++)
	{
		printf("%ld\n",ghostsArrayTrophy[k]);
	}
*/
	

	Day dayArray[numDays];
	for(long x = 0;x<numDays;x++)
	{
		scanf("%ld",&currentDayWinnerAge);
		if(x == 0)
		{
			//ghostsArrayTrophy[currentDayWinnerAge] = ghostsArrayTrophy[currentDayWinnerAge]+1;
			ageToWinMap[currentDayWinnerAge] = 1;
			//printf("%ld => \n",currentDayWinnerAge);
			//printf("%ld => \n",ghostsArrayTrophy[currentDayWinnerAge]);


			tempDay.ageOfConsistent = currentDayWinnerAge;
			tempDay.numTrophyWon = ageToWinMap[currentDayWinnerAge];
			dayArray[x] = tempDay;
			continue;
		}else{
			oldDay = dayArray[x-1];

			//ghostsArrayTrophy[currentDayWinnerAge] = ghostsArrayTrophy[currentDayWinnerAge]+1;
			if (ageToWinMap.count(currentDayWinnerAge))
			{
				ageToWinMap[currentDayWinnerAge] = ageToWinMap[currentDayWinnerAge] + 1;
			}else{
				ageToWinMap[currentDayWinnerAge] = 1;
			}

			//same age	
			if(currentDayWinnerAge == oldDay.ageOfConsistent)
			{
				tempDay.ageOfConsistent = currentDayWinnerAge;
				tempDay.numTrophyWon =ageToWinMap[currentDayWinnerAge] ;
				dayArray[x] = tempDay;
				continue;
			}

			//comapare num trophy
			if(oldDay.numTrophyWon > ageToWinMap[currentDayWinnerAge])
			{
				tempDay.ageOfConsistent = oldDay.ageOfConsistent;
				tempDay.numTrophyWon = ageToWinMap[oldDay.ageOfConsistent];
				dayArray[x] = tempDay;
				continue;
			}else if(oldDay.numTrophyWon == ageToWinMap[currentDayWinnerAge]){
				if(oldDay.ageOfConsistent < currentDayWinnerAge)
				{
					tempDay.ageOfConsistent = currentDayWinnerAge;
					tempDay.numTrophyWon = ageToWinMap[currentDayWinnerAge];
					dayArray[x] = tempDay;
					continue;
				}else{
					tempDay.ageOfConsistent = oldDay.ageOfConsistent;
					tempDay.numTrophyWon = ageToWinMap[oldDay.ageOfConsistent];
					dayArray[x] = tempDay;
					continue;
				}
			}else{
				    tempDay.ageOfConsistent = currentDayWinnerAge;
					tempDay.numTrophyWon = ageToWinMap[currentDayWinnerAge];
					dayArray[x] = tempDay;
					continue;
			}
		}
	}

	for(long test = 0;test < numDays;test++)
	{
		tempDay = dayArray[test];
		printf("%ld %ld\n",tempDay.ageOfConsistent,tempDay.numTrophyWon);
	}
}
