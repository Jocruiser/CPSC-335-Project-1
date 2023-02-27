#CPSC-335-Project-1  
Algorithm 2:  Matching Group Schedules  
Group Members:  
Andres Gallego - andresgallego@csu.fullerton.edu  
Joanna Cruz - joannacruz@csu.fullerton.edu  

Problem was implemented using C++  

The string of Time was converted to minutes, minutes were then converted into a string for 24 hr time  
Schedules and Daily active times from both persons were combined into a vector to find available times  
Daily active times were converted into minutes, and both schedules were combined to sort by the start time  
Available time slots were found by skipping if the schedule overlaps with the other  
If a gap is present between both schedules, it is added into available times  


