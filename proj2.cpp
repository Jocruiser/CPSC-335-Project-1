
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
	int i = 0, j = 0, k = 0;
	//traverse person 1 array and insert into the array for both
	while (i < n1) {
	arrboth[k++] = pers1Schedule[i++];
	}
	
	//traverse person 2 array and insert it into the array for both
	while (j < n2) {
	arrboth[k++] = pers2Schedule[j++];
	}
	
	//sort the combination array for both
	sort(arrboth, arrboth+n1+n2);
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

	int pers1Schedule[] = {7, 8, 12, 13, 16, 18};
	int n1 = sizeof(pers1Schedule) / sizeof(pers1Schedule[0]);
	
	int pers2Schedule[] = {9, 10, 12, 14, 15, 16, 17};
	int n2 = sizeof(pers2Schedule) / sizeof(pers2Schedule[0]);
	
	int arrboth[n1+n2];
	mergeArrays(pers1Schedule, pers2Schedule, n1, n2, arrboth);
	
	std::cout << "Array after merging" << endl;
	
	for(int i = 0; i < n1+n2; i++)
	std::cout<< arrboth[i] << " ";
	
	
	return 0;
	
	}
