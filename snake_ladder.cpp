#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

class VertexInfo
{
	public :
	int number;
	int distance;
};

int getMinAttempt(int moves[],int size)
{

	bool visited[size];
	for(int x =0;x<size;x++)
	{
		visited[x] = false;
	} 

	VertexInfo tempVertexInfo;

	VertexInfo vertexInfo;
	vertexInfo.number = 0;
	vertexInfo.distance = 0;

	queue<VertexInfo> myQueue;
	myQueue.push(vertexInfo);

	while(!myQueue.empty())
	{
		tempVertexInfo = myQueue.front();
		if(tempVertexInfo.number == size-1)
		{
			return tempVertexInfo.distance;
		}
		myQueue.pop();
		visited[tempVertexInfo.number] = true;

		for(int x = tempVertexInfo.number;x < tempVertexInfo.number+7 && x <size; ++x)
		{
			if(!visited[x])
			{
				VertexInfo newVertexInfo;
				int number = moves[x] == -1 ? x : moves[x];
				newVertexInfo.number = number;
				newVertexInfo.distance = tempVertexInfo.distance + 1;
				myQueue.push(newVertexInfo);
			}
		}	

	}



}

int main()
{
	int size = 30;
	int moves[size];

	for(int k =0 ;k<size ;k++)
	{
		moves[k] = -1;
	}

	// Ladders
    moves[2] = 21;
    moves[4] = 7;
    //moves[5] = 29;
    moves[10] = 25;
    moves[19] = 28;
 
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout << "Moves needed = " << getMinAttempt(moves,size) << endl;

}