/* Name: Abhinav Jonnada
   WSU id: b956d578
   WSU email id: axjonnada@shockers.wichita.edu
   */


#include <iostream>
#include "Buffer.hpp"



using namespace std;

//initalize buffer entries with -1

Buffer::Buffer() {
	
		for (int i = 0; i < SIZE; i++) {
			itemsArray[i] = -1;
}
}


void Buffer::insertItem(int item){
	
	buffAccess.lock(); //get the mutex lock
	
	itemsArray[in] = item; // enter the critical section
	in =  (in + 1) % SIZE; // exit he criticla section
	
	buffAccess.unlock(); //release the mutex lock
	
}


void Buffer::removeItem(int& item){
	
	buffAccess.lock(); //get the mutex lock
	
	item = itemsArray[out]; // enter the critical section
	out =  (out + 1) % SIZE; // exit he criticla section
	
	buffAccess.unlock(); //release the mutex lock
	
}



