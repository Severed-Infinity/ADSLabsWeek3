#include <iostream>
#include <string>
//#include <chrono>
//#include <thread>
using namespace std;

//http://www.cplusplus.com/forum/beginner/26775/

int input(int& hour, int& minutes){
	cout << "Enter the 24 hour time: ";
	cin >> hour >> minutes;
	while (hour > 23 || hour < 0 || minutes > 59 || minutes < 0){
		cout << "Invalid time format." << endl;
		input(hour, minutes); //recursive-form
		//cin >> hour >> minutes; //non-recursive-from
	}
	return hour;
}

int conversion(int& hour, char& ampm){
	//ternary opertation only works for single value assignment
	//hour = hour > 12 && hour < 24 ? hour -= 12 : hour == 0 ? 12 : hour;

	//preferential to ternary operations, but cannot be used entirely in this circumstance

	if (hour > 12 && hour < 24){
		hour -= 12;
		ampm = 'P';
	}
	else if (hour == 0){
		hour = 12;
		ampm = 'A';
	}
	else if (hour == 12){
		ampm = 'P';
	}
	else {
		ampm = 'A';
	}
	return hour;
}

int output(int& hour, int& minutes, char& ampm){
	cout << to_string(hour) << ":" << to_string(minutes) << " " << (ampm == 'A' ? "A.M" : "P.M") << endl;
	return 0;
}

/*int clock(){
	int hourTest = 0, minuteTest = 0;
	while (true){
		if (minuteTest > 59){
			hourTest++;
			minuteTest = 0;
		}
		if (hourTest > 12){
			hourTest = 0;
		}

		cout << (hourTest == 0 ? 12 : hourTest) << ":" << minuteTest << endl;
		minuteTest++;
		chrono::milliseconds duration(1000);
		this_thread::sleep_for(duration);
	}
}*/
/*int main() {

	int hour = 0, minutes = 0;
	char ampm, yn;

	do {
		input(hour, minutes);
		conversion(hour, ampm);
		cout <<"conversion "<< conversion(hour, ampm);
		output(hour, minutes, ampm);
		cout << "Do you wish to convert another time? ";
		cin >> yn;
	} while (yn == 'y');	
	//clock();
	system("pause");
	return 0;
}*/