
#include <bits/stdc++.h>
using namespace std;

/*
struct Time
{
	int hour;
	int minute;
	int seconds;

// def constructor 
Time():Time(0,0,0){}
Time(int hour, int min, int sec) // assign parameters to const
{
	hour = hr;
	minute = min;
	seconds = sec;
}; 
*/

void mergeArrays (int pers1Schedule[], int pers2Schedule[], int n1, int n2, int arrboth[])

{
	int p1 = 0, p2 = 0, k = 0;
	//traverse person 1 array and insert into the array for both
	while (p1 < n1) {
	arrboth[k++] = pers1Schedule[p1++];
	}
	
	//traverse person 2 array and insert it into the array for both
	while (p2 < n2) {
	arrboth[k++] = pers2Schedule[p2++];
	}
	
	//sort the combination array for both in acsending order
	sort(arrboth, arrboth+n1+n2);
}

void unavail_times (int pers1_DailyAct[], int pers2_DailyAct[], int q1, int q2, int block_schedule[])
{	
	//traverse unavailable time arrays from both and subtract times from arrboth
	int u1 = 0, u2 = 0, j = 0;
	while (u1 == q1) {
	block_schedule[j++] = pers1_DailyAct[u1--];
	}
	
	// traverse unavailable pers2 and subtract from arrboth
	while (u2 == q2) {
	block_schedule[j++] = pers2_DailyAct[u2--];
	}
	

}

	
/*

int main() {

  std::string pers1Schedule, pers1DailyAct;
  // 1. Ask the user for person1's schedule, and the person 1 daily activity.
  std::cout << "Enter schedule for person 1: ";
  std::getline(std::cin, pers1Schedule);
  
  std::cout << "Enter Daily Availability for person 1: ";
  std::getline(std::cin, pers1DailyAct);
  
  std::string pers2Schedule, pers2DailyAct;
  // 2. Ask the user for person2's schedule, and the person 2 daily activity.
  std::cout << "Enter schedule for person 2: ";
  std::getline(std::cin, pers2Schedule);
  
  std::cout << "Enter Daily Availability for person 2: ";
  std::getline(std::cin, pers2DailyAct);
  
  std::string dur_of_meeting;
  std::cout << "Enter the duration of the meeting ";
  std::getline(std::cin, dur_of_meeting);

}
*/

int main() {

	int meeting_duration = 30;
	
	int pers1_DailyAct[] = {9, 19};
	int block1 = sizeof(pers1_DailyAct) / sizeof(pers1_DailyAct[0]);
	
	int pers2_DailyAct[] = {9, 18};
	int block2 = sizeof(pers2_DailyAct) / sizeof(pers2_DailyAct[0]);

	int pers1Schedule[] = {7, 8, 12, 13, 16, 18};
	int n1 = sizeof(pers1Schedule) / sizeof(pers1Schedule[0]);
	
	int pers2Schedule[] = {9, 10, 12, 14, 15, 16, 17};
	int n2 = sizeof(pers2Schedule) / sizeof(pers2Schedule[0]);
	
	int arrboth[n1+n2];
	mergeArrays(pers1Schedule, pers2Schedule, n1, n2, arrboth);
	
	// take combined arrays and subtract the daily activites from both schedules
	int block_schedule[n1+n2-block1-block2];
	unavail_times(pers1_DailyAct, pers2_DailyAct, n1, n2, block_schedule);
	
	std::cout << "Array after merging" << endl;
	
	for(int i = 0; i < n1+n2-block1-block2; i++)
	std::cout<< arrboth[i] << " ";
	
	
	return 0;
	
	}
