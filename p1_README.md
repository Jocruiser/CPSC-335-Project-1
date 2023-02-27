# CPSC-335-Project-1
Algorithm 1
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
