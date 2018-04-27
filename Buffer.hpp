/* Name: Abhinav Jonnada
   WSU id: b956d578
   WSU email id: axjonnada@shockers.wichita.edu
   */


#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <iostream>

#include <mutex>


using namespace std;

const int SIZE = 5; //buffer size

class Buffer {

public: 
     Buffer();
     //use buffAccess to get exclusive access to the buffer
     void insertItem(int item);
     void removeItem(int& item);
     
private:
     
     int  itemsArray[SIZE];
     mutex buffAccess;
     int in, out;
     
     
};
#endif
