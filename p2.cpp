/*
CPSC 335 - Project 1 - Algorithm 2
Andres Gallego - andresgallego@csu.fullerton.edu
Joanna Cruz - joannacruz@csu.fullerton.edu 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// helper function to convert minutes since midnight to time string
string minutesToTime(int minutes) {
    int hours = minutes / 60;
    int mins = minutes % 60;
    return (hours < 10 ? "0" : "") + to_string(hours) + ":" + (mins < 10 ? "0" : "") + to_string(mins);
}

// helper function to convert time string to minutes since midnight
int timeToMinutes(string timeStr) {
    int hours = stoi(timeStr.substr(0, 2));
    int minutes = stoi(timeStr.substr(3, 2));
    return hours * 60 + minutes;
}

// function for finding common availbility time between both people
vector<pair<int, int>> findAvailableTimes(vector<vector<string>> person1_Schedule, vector<string> person1_DailyAct, 
                                                vector<vector<string>> person2_Schedule, vector<string> person2_DailyAct, 
                                                int duration) 
{
    // combine schedules and daily activities into one list of unavailable times
    vector<pair<int, int>> unavailableTimes; 
    
   
    for (auto& slot : person1_Schedule) {
        unavailableTimes.emplace_back(timeToMinutes(slot[0]), timeToMinutes(slot[1]));
    }
    for (auto& slot : person2_Schedule) {
        unavailableTimes.emplace_back(timeToMinutes(slot[0]), timeToMinutes(slot[1]));
    }
    
    //sorting in increasing order
    sort(unavailableTimes.begin(), unavailableTimes.end());

    vector<pair<int,int>> availableTimes;
    
    int begin_time = max(timeToMinutes(person1_DailyAct[0]),timeToMinutes(person2_DailyAct[0]));
    int block_end_time = min(timeToMinutes(person1_DailyAct[1]),timeToMinutes(person2_DailyAct[1]));
    int prevous_end_time = begin_time;
    
    //finding available times using unavailableTimes array
    for(auto& slot: unavailableTimes){
        //if overlap between the schedules is found skip to the next iteration
        if(slot.first < begin_time || slot.second > block_end_time){
            continue;
        }
        
        //If there is an open slot between the previous slot and the current slot then add open slot to availableTimes
        else if(slot.first - prevous_end_time >= duration){
            availableTimes.push_back({prevous_end_time, slot.first});
        }
        
        //updates the prevous_end_time
        prevous_end_time = max(prevous_end_time, slot.second);
    }
    //add an availble time slot for the gap between the end of the last schedule to the end of the dailyAct time.
    if(block_end_time - prevous_end_time >= duration){
        availableTimes.push_back({prevous_end_time, block_end_time});
    }

    
    return availableTimes;
}


int main() {
    vector<vector<string>> person1_Schedule = {{"07:00", "08:30"}, {"12:00", "13:00"}, {"16:00", "18:00"}};
    vector<string> person1_DailyAct = {"09:00", "19:00"};
    vector<vector<string>> person2_Schedule = {{"09:00", "10:30"}, {"12:20", "14:30"}, {"14:00", "15:00"}, {"16:00", "17:00"}};
    vector<string> person2_DailyAct = {"09:00", "18:30"};
    int duration_of_meeting = 30;

    vector<pair<int, int>> availableTimes = findAvailableTimes(person1_Schedule, person1_DailyAct, 
                                                                     person2_Schedule, person2_DailyAct, 
                                                                     duration_of_meeting);
    for (auto& slot : availableTimes) {
        cout << "[" << minutesToTime(slot.first) << ", " << minutesToTime(slot.second) << "]" << endl;
    }
    return 0;
}
