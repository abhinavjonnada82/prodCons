/* Name: Abhinav Jonnada
   WSU id: b956d578
   WSU email id: axjonnada@shockers.wichita.edu
   */



#include <stdio.h>
#include <semaphore.h> //for creating full, and empty semaphores
#include <thread> //for creating pthread mutex loxks
#include <stdlib.h> //for rand()
#include <iostream> //for cin cout
#include <cstdlib> //for using atoi (string to int)
#include "Buffer.hpp"
#include <unistd.h> //for sleep()
#include <mutex>



void producer(int prodId);
void consumer(int consId);
// The producer and consumer threads use full and empty semaphores.
Buffer bffr[2];
mutex test;
const double FACTOR = 0.000000001;
sem_t full[2], empty[2]; //These are the semaphores

int main (int argc, char *argv[]) { //get command line arguments argc and argv
	

	if (argc < 4 ) {
		cout << "way to many arguments" << endl;
	}
	//Assign variables
	int sleepTime = atoi(argv[1]);
	int numProducers = atoi(argv[2]);
	int numConsumers = atoi(argv[3]);

   //create and initialize the semaphores
   
   for (int i = 0; i <2; i++) {
	   sem_init(&full[i], 0, 0);
	   sem_init(&empty[i], 0, SIZE);
	 
	
	   /* Create the semaphore and initialize it to 1 */
	   //sem_init(&sem, 0, 1);
   }
     
   
    thread prod_thread[numProducers];
   //create numProducer producer threads
   for (int i = 0; i < numProducers; i++) {
	   prod_thread[i]=thread(producer, i);
   }
   
   //create numCosumer consumer threads
       thread cons_thread[numConsumers];
   //create numProducer producer threads
   for (int i = 0; i < numConsumers; i++) {
	   cons_thread[i]=thread(consumer, i);
   }
   
   
   //sleep
   sleep(sleepTime);
   
   //exit
   exit(0);
}
   
   

void producer(int prodId) {
	int item;
	int x; //how long the producer sleeps
	int whichBuffer; //rand() will choose which buffer number
	
	while (true) {
		x = rand()*FACTOR;
		sleep(x); //// sleep for x units of time
		item = rand() % 100; //// generate a random number as item
		whichBuffer = rand()%2;
		sem_wait(&empty[whichBuffer]); /* acquire the semaphore */
		
		//test.lock();
		bffr[whichBuffer].insertItem(item);
		//test.unlock();
	
		sem_post(&full[whichBuffer]); /* release the semaphore */
		
		cout << "Producer " << prodId << " inserted " << item << " into buffer " << whichBuffer << endl;
	
	}
}

void consumer(int consId) {
	int item;
	int x;
	int whichBuffer;
	
	while(true) {
		x=rand()*FACTOR;
		sleep(x);
		item = rand() % 100; //generate a random number as item
		whichBuffer = rand()%2;
		
		sem_wait(&full[whichBuffer]); /* acquire the semaphore */
		
		//test.lock();
		bffr[whichBuffer].removeItem(item);
		////test.unlock();
		
		sem_post(&empty[whichBuffer]); /* release the semaphore */
		
		cout << "Consumer " << consId << " consumed " << item <<" from buffer " << whichBuffer << endl;
		
		
	}
}
	
	
	 

