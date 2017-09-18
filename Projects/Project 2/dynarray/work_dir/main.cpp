/**
This is the tester program for the dynarr.h file

Last edited: 9-18-17
Author: Riley Wells
*/

#include "dynarr.h"

using namespace std;

int main(){
	
	//declare two dynarr objects
	dynarr<int> arr1;
	dynarr<int> arr2(10);

	int cap1 = 10;
	int cap2 = 12;
	
	//test the reserve and getCapacity function on arr1 object
	cout << "arr1 capacity b4 reserve: " << arr1.getCapacity() << endl;
	arr1.reserve(cap1);
	cout << "arr1 capacity after reserve: " << arr1.getCapacity() << endl;

	//initialize the elements of arr1
	for(int i = 0; i < arr1.getCapacity(); ++i)
		arr1[i] = i * 5;

	//print out the elements of arr1
	cout << endl << "elements of arr1" << endl;
	for(int i = 0; i < arr1.getCapacity(); ++i)
		cout << arr1[i] << endl;
	cout << endl;

	//initialize the elements of arr2
	for(int i = 0; i  < 10; ++i)
		arr2[i] = i * 2; 

	//printout the elemements of arr2 in a try-catch block to test the runtime exception
	//for an invalid element
	cout << "elements of arr2" << endl;
	try{
		for(int i = 0; i <= 10; ++i)
			cout << arr2[i] << endl;
	}
	catch(InvalidIndex& e){
		cout << e.getMessage() << endl;
	}	

	//change the size of arr2 array to 12
	arr2.reserve(cap2);

	//deep copy of arr2 to arr1
	arr1 = arr2;

	cout << "new capacity of arr1: " << arr1.getCapacity() << endl;
	cout << "new capacity of arr2: " << arr2.getCapacity() << endl;
	arr2.~dynarr();

	cout << "new elements of arr1" << endl;
	for(int i = 0; i < arr1.getCapacity(); ++i)
		cout << arr1[i] << endl;
	cout << endl;

	dynarr<int> arr3(arr1);
	cout << "arr3 capacity: " << arr3.getCapacity() << endl;
	for(int i = 0; i < arr3.getCapacity(); ++i)
		cout << arr3[i] << endl;



	return 0;

}
