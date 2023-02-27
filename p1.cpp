/*
CPSC 335 - Project 1 - Algorithm 1
Andres Gallego - andresgallego@csu.fullerton.edu
Joanna Cruz - joannacruz@csu.fullerton.edu 
*/

#include <iostream>
#include <vector>

/*
- Cities are connected in circular roads
- Roads run clockwise
- Use Greedy Approach (most optimal choice at every stage/step)
- Car starts with 0 gas 
- Cities have gas stations
- Last road is connect to the first road
- guaranteed that there will be one solution

The Brute Force method for us would be to start every position as the starting position until we find the solution. O(n^2).

The Greedy Approach in this case: At each stage we always select the best starting point, the best starting point is the starting point that can get the car to the next city.


INPUTS:
- First array is the distance b/w neighboring cities
    [2,25,15,10,5]
        -> city i is distance[i] away from city i + 1 

- Second array are the gas quantity available at each gas station
    [1,2,1,0,3]
        -> city i has gas[i] 

- MPG = 10

OUTPUT:
- The Starting city 
    -> city 4
*/

//this algorithm is assuming that there is always a valid solution.
int Greedy_Hamilton_Problem(const std::vector<int>& city_distances_in_miles ,const std::vector<int>& gas, int& mpg)
{
    int start = 0, current_tank = 0; 
    
    for(int i = 0; i < gas.size(); i++)
    {
        // Converting city_distance into gallons and then finding the difference between amount of gas avaliable and city_distance in gallons. 
        current_tank += gas[i] - city_distances_in_miles[i] / (float)mpg;
        
        //if current_tank equals 0 that means current city is not the starting point so try the next city (i+1) as the starting point and reset the tank. 
        if(current_tank < 0)
        {
            start = i + 1;
            current_tank = 0;
        }
    }
    return start;

}

int main()
{
    std::vector<int> a;
    a.push_back(5);
    a.push_back(25);
    a.push_back(15);
    a.push_back(10);
    a.push_back(15);

    std::vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(1);
    b.push_back(0);
    b.push_back(3);
    
    int mpg = 10;

    std::cout << Greedy_Hamilton_Problem(a, b, mpg) << std::endl;
}




