#include <iostream>
using namespace std;

int InputAndAverage5(){
	int n[5], total = 0, average = 0; 
	for (int i = 0; i < 5; i++){
		cout << "Enter value " << (i + 1) << " of 5. ";
		cin >> n[i];
		total += n[i];
	}
	average = total / 5;
	cout << endl <<"The average of the input was: " << average << endl;
	for (int i = 0; i < 5; i++){
		cout << "Value " << (i + 1) << " requires " << (average - n[i]) << " to be average." << endl;
	}
	return 0;
}

int Average5(int inputs[]){
	int total = 0;
	for (int i = 0; i < 5; i++){
		total += inputs[i];
	}
	int average = total / 5;
	cout <<endl<< "The average of the input was: " << average << endl;
	for (int i = 0; i < 5; i++){
		cout << "Value " << (i + 1) << " requires " << (average - inputs[i]) << " to be average." << endl;
	}
	
	return 0;
}

int AverageN(int inputs[], int inputsSize){
	int total = 0;
	for (int i = 0; i < inputsSize; i++){
		total += inputs[i];
	}
	int average = total / inputsSize;
	cout << endl << "The average of the input was: " << average << endl;
	for (int i = 0; i < inputsSize; i++){
		cout << "Value " << (i + 1) << " requires " << (average-inputs[i]) << " to be average." << endl;
	}
	return 0;
}

void arrayAverageDriver(){
	cout << "InputsAndAverages5()" << endl;
	InputAndAverage5();

	cout << endl << "Average5()" << endl;
	int inputs1[5], i = 0;
	while (i < 5){
		cout << "Enter value " << (i + 1) << " to be added to the array. ";
		cin >> inputs1[i];
		i++;
	}
	Average5(inputs1);

	cout << endl << "AverageN()" << endl;
	int size;
	cout << "Enter the size of the array: ";
	cin >> size;
	int* inputs2 = new int[size];
	for (int i = 0; i < size; i++){
		cout << "Enter value " << (i + 1) << " to be added to the array. ";
		cin >> inputs2[i];
	}
	AverageN(inputs2, size);
}

bool fillArray(char halfFilledArray[], int maxSize, int& filledSize){
	int index = 0;
	while (halfFilledArray[index] != '.' || index < maxSize){
		cout << "Input a character: ";
		cin >> halfFilledArray[index];	
		if (halfFilledArray[index] == '.'){
			filledSize = index;
			return true;
		}
		index++;
	}
	filledSize = index;
	return false;
}

int outputInReverse(char array[], int& filledSize){
	cout << "Array in reverse: ";
	for (int i = filledSize; i > -1; i--){
		cout << array[i];
	}
	cout << endl;
	return 0;
}

void halfFilledArrayDriver(){
	cout << "fillArray()" << endl;
	int const maxSize = 100;
	int filledSize = 0;
	char halfFilledArray[maxSize];

	fillArray(halfFilledArray, maxSize, filledSize);
	cout << "Used space in the array was: " << filledSize << endl;
	outputInReverse(halfFilledArray, filledSize);
}

int main() {
	arrayAverageDriver();
	halfFilledArrayDriver();
	
	system("pause");
	return 0;
}