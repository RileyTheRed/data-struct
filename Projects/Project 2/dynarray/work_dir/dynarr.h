/*
This is the header file that contains the class declarations and function
definitions for RuntimeException, InvaildIndex, and most importantly
the templated dynarr class and its functions.

Author: Riley Wells
*/

#include <cassert>
#include <iostream>
#include <string>

class RuntimeException // generic run-time exception
{
 protected:
  std::string errorMsg;
 public:
  RuntimeException(const std::string& err) { errorMsg = err; }
  std::string getMessage() const { return errorMsg; }
};

class InvalidIndex : public RuntimeException
{
 public:
  InvalidIndex(const std::string& err): RuntimeException(err) {};
};

template <class dynElem>
class dynarr {
  private:
    int capacity;
    dynElem *A;
  public:
    dynarr() : capacity(0), A(NULL) {};
    dynarr(int N): capacity(N), A(new dynElem[N]){};
    dynarr(const dynarr<dynElem> &other);
    ~dynarr();
    dynarr<dynElem> & operator=( const dynarr<dynElem> &other);
    dynElem & operator[](int ndx) throw (InvalidIndex);
    int getCapacity();
    void reserve(int newcap);
    // if newcap <= capacity, does nothing; 
    // if capacity is 0, allocates a dynamic array of
    // capacity newcap and makes A point to that array;
    // otherwise allocates a new dynamic array newA of capacity 
    // newcap, copies values in A to newA, deletes A and sets
    // A equal to newA
};



/*

dynarr(const dynarr<dynElem> &other)

const dynarr<dynElem> &other - The reference to the dynamic array to be copied

PURPOUSE:
	This function takes in a reference to a dynamic array of type dynElem
	and creates a deep copy of the refence which will be the newly created instance.

RETURN: NONE

*/
template <class dynElem>
dynarr<dynElem>::dynarr(const dynarr<dynElem> &other)
{

	capacity = other.capacity;
	A = new dynElem[capacity];
	
	for(int i = 0; i < capacity; ++i){
		A[i] = other.A[i];
	}

}


/*

~dynarr()

PURPOSE:
	This is the destructor for the dynamic array object. It deletes the allocated
	memory space and sets the A member of the instance to a nullptr.

RETURN: NONE

*/
template <class dynElem>
dynarr<dynElem>::~dynarr()
{
	
	delete[] A;
	A = nullptr;
	
}


/*

dynarr<dynElem>& operator=(const dynarr<dynElem> &other)

PURPOSE:
	The overlaoded assignment operator creates a deep copy of the dynamic array
	passed by reference and sets the instance to be qual to other.

RETURN:
	If the two objects are the same, then the function returns a pointer to the instance

	Else, it copies the information from other into the instance and retrusn the reference
	to the instance.

*/
template <class dynElem>
dynarr<dynElem> & dynarr<dynElem>::operator=( const dynarr<dynElem> &other)
{

	if(this == &other)
		return *this;
	else{
		capacity = other.capacity;

		delete[] A;
		A = new dynElem[capacity];

		for(int i = 0; i < capacity; ++i)
			A[i] = other.A[i];
	}

	return *this;
  
}


/*

dynElem& operator[](int ndx) throw(InvalidIndex)

int ndx - The desired index of the dynamic array

PRUPOSE: 
	The overloaded [] operator takes an integer value ndx and returns
	the dynElem at ndx of the array A

RETURN:
	If ndx < 0 or ndx >= the capacity of the dynamic array, an InvalidIndex
	error is thrown.

	Otherwise, the value at A[ndx] is returned.

*/  
template <class dynElem>
dynElem & dynarr<dynElem>::operator[](int ndx) throw(InvalidIndex)
{

	if(ndx < 0 || ndx >= capacity)
		throw(InvalidIndex("The index does not exist"));
	else
		return A[ndx];

}


/*

int getCapacity()

PURPOSE:
	This function returns the capacity of the instance object.

RETURN: 
	Returns the capacity of the instance

*/
template <class dynElem>
int dynarr<dynElem>::getCapacity()
{

	return capacity;

}


/*

void reserve(int newcap)

PURPOSE:
	If newcap <= capacity, the function does nothing.

	If the capacity of the instance is 0, then create a new 
	dynamically allocated array of type dynElem, make A point to 
	the new array, and set acapacity to newcap.

	If newcap > capacity, create a new dynamically allocated array of size newcap
	and copy the values from A to the new array. Delete A, and set A to the new array.
	Lastly, set capacity to newcap.

RETURN:
	NONE

*/
template <class dynElem>
void dynarr<dynElem>::reserve(int newcap)
{

	if(newcap <= capacity) ;
	else if(capacity == 0){
		dynElem *newA = new dynElem[newcap];
		A = newA;
		capacity = newcap;
	}
	else{
		dynElem *newA = new dynElem[newcap];
		for(int i = 0; i < capacity; ++i)
			newA[i] = A[i];
		delete[] A;
		A = newA;
		capacity = newcap;
	}
}
