#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// gas distance to get from one destination to the next fuel pump
class gasDistance
{
	public:
	int station;
	int distance;
};

//function will return the starting point 
int circuit(gasDistance arr[], int g)
{
//first gas station is the starting point sets array as a queue
//if the gas is enough to reach the next destination then the end pointer is incremented 
	int start = 0;
	int end = 1;

//takes the starting station and subtracts the distance it takes	
int curr_station = arr[start].station - arr[start].distance;

//loop through all gas stations until the first gas station is reached with fuel

	while (end !=start || curr_station < 0)
	{
		// if amount of fuel becomes less than 0 remove starting gas station from 			//circuit
		while (curr_station < 0 && start != end)
		{
			// remove the starting gas station and changes the start
			curr_station = arr[start].station - arr[start].distance;
			start = (start + 1) % g;
			
		  if (start == 0)
		  return -1;
		}
		
		//Add a gas station to the current circuit
		curr_station += arr[end].station - arr[end].distance;
		
		end = (end + 1) % g;
		
	}
	// returns the starting point
	return start;
}
int main()
{
	gasDistance arr[] = {{5,1}, {25, 2}, {15, 1}, {10,0}, {15, 3}};
	
	int g = sizeof(arr)/sizeof(arr[0]);
	int start = circuit(arr, g);
	
	(start == -1)? 
	std::cout<<"No Solution": std::cout<<"Start = " << start;

  return 0;
}
