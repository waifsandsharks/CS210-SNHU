

#include<iostream>
using namespace std;
class clock24HourTime;

/* Creates an enumeration of a constant for Am and Pm
 * Sourced from:
 * Karthikeya Boyini
 * Published on 08-Nov-2018 10:10:28
 * How to use enums in C++?
 * https://www.tutorialspoint.com/how-to-use-enums-in-cplusplus#:~:text=Enumeration%20is%20a%20user%20defined,is%20the%20syntax%20of%20enums.&text=The%20following%20is%20an%20example%20of%20enums.com
 */
enum AMPM{AM, PM}
ampm;

// This creates a public class time with variables for hour minute and second

class Time{
public:
int hr;
int min;
int sec;

/* This starts our methods out with 0.
 * Virtual void soured from:
 * Virtual Function in C++
 *  Last Updated : 10 Feb, 2020
 *  https://www.geeksforgeeks.org/virtual-function-cpp/
 */
virtual void add1Hr() = 0;
virtual void add1Min() = 0;
virtual void add1Sec() = 0;
};

// this constructs our 12 hour clock and allows it to inherit from the time class
class clock12HourTime : public Time{
public:
clock12HourTime(int h , int m , int s){
	hr = h;
	min = m;
	sec = s;
	ampm = AM;
}
// clock12HourTime methods
void add1Hr(){
	if(hr == 11){
		hr = 0;
		ampm = ampm == AM ? PM : AM;
	}
	else{
		hr += 1;
	}
}
void add1Min(){
	if(min == 59){
		min = 0;
		add1Hr();
	}
	else{
		min += 1;
	}
}
void add1Sec(){
	if(sec == 59){
		sec = 0;
		add1Min();
	}
	else{
		sec += 1;
	}
}
/* The friend function is used to allow one
 *  function access to anothers private classes.
 *  Source from:
 *  Friend class and function in C++
 *  08 AUG, 2019
 *  https://www.geeksforgeeks.org/friend-class-function-cpp/
 */
friend void displayTime(const clock12HourTime& ,const clock24HourTime&);
};

// this constructs our 24 hour clock and allows it to inherit from the time class
class clock24HourTime : public Time{
public:

	// clock24HourTime methods
clock24HourTime(int h , int m , int s){
hr = h;
min = m;
sec = s;
}

void add1Hr(){
	if(hr == 23){
		hr = 0;
	}
	else{
		hr += 1;
	}
}
void add1Min(){
	if(min == 59){
		min = 0;
		add1Hr();
	}
	else{
		min += 1;
	}
}
void add1Sec(){
	if(sec == 59){
		sec= 0;
		add1Min();
	}
	else{
		sec += 1;
	}
}

/* The friend function is used to allow one
 *  function access to another's private classes.
*/
friend void displayTime(const clock12HourTime& ,const clock24HourTime&);
};
// This builds the boxes for the two clocks.
void displayTime(const clock12HourTime& time12 ,const clock24HourTime& time24){
cout << "xXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX\n";
cout << "X 12-Hour Clock xXxXxXxXxXxXx 24-Hour Clock    X\n";
cout << "X "; if(time12.hr < 10) cout << "0"; cout << time12.hr << ":";
if(time12.min < 10 ) cout << "0" ; cout << time12.min << ":";
if(time12.sec < 10) cout << "0"; cout << time12.sec;
if(ampm == AM ) cout << " am"; else cout << " pm";
cout << " xXxXxXxXxXxXx ";
if(time24.hr < 10) cout << "0"; cout << time24.hr << ":";
if(time24.min < 10 ) cout << "0" ; cout << time24.min << ":";
if(time24.sec < 10) cout << "0"; cout << time24.sec;
cout << "           X\n";
cout << "xXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxXxX\n";
}

// This will build our boxes for out options
int main(){
	clock12HourTime time_12_Clock(11 , 59 , 59 );
	clock24HourTime time_24_Clock(23,59,59);
	displayTime(time_12_Clock , time_24_Clock);
	while(true){
		cout << "_-_-_-_-_-_-_-_-_-_-_-_-_\n";
		cout << "| 1 - Add One to Hour   |\n";
		cout << "| 2 - Add One to Minute |\n";
		cout << "| 3 - Add One to Second |\n";
		cout << "| 4 - Exit the Program  |\n";
		cout << "|_-_-_V enter below V_-_|\n";

int choice;
cin >> choice;
/* Switch and case statments used to display options 1-4
 *if user selects option outside of 1-4 terminal gives issue:
 *"Error! pick 1-4 please!"
 *if user selects option 4:
 * "ED - have a nice day!"
 * source from:
 * Microsoft
 *  on: 01/20/2021
 * pub: 04/25/2020
 * https://docs.microsoft.com/en-us/cpp/cpp/switch-statement-cpp?view=msvc-160
 *
 */
switch (choice){
case 1:
	time_12_Clock.add1Hr();
	time_24_Clock.add1Hr();
	displayTime(time_12_Clock , time_24_Clock);
	break;

case 2:
	time_12_Clock.add1Min();
	time_24_Clock.add1Min();
	displayTime(time_12_Clock , time_24_Clock);
	break;

case 3:
	time_12_Clock.add1Sec();
	time_24_Clock.add1Sec();
	displayTime(time_12_Clock , time_24_Clock);
	break;

case 4:
	cout << "ED - have a nice day!";
	exit(1);
	break;

default:
	cout << "Error! pick 1-4 please!\n";
	break;
}
}
}
