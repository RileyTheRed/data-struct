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

template <class dynElem>
dynarr<dynElem>::dynarr(const dynarr<dynElem> &other)
{

	capacity = other.capacity;
	A = new dynElem[capacity];
	
	for(int i = 0; i < capacity; ++i){
		A[i] = other.A[i];
	}

	//return *this;

}

template <class dynElem>
dynarr<dynElem>::~dynarr()
{
	
	delete[] A;
	A = nullptr;
	
}

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
  
template <class dynElem>
dynElem & dynarr<dynElem>::operator[](int ndx) throw(InvalidIndex)
{

	if(ndx < 0 || ndx >= capacity)
		throw(InvalidIndex("The index does not exist"));
	else
		return A[ndx];

}

template <class dynElem>
int dynarr<dynElem>::getCapacity()
{

	return capacity;

}
  
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
