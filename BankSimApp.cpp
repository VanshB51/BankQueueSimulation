/* 
 * BankSimApp.cpp
 *
 * Description: Bank simulation app
 *
 * Class Invariant: 
 * 
 * Author: Vansh Bansal and Adityapal Waraich
 * Last Modification: Nov. 2023
 *
 */
#include <iostream>
#include "BinaryHeap.h"
#include "PriorityQueue.h"
#include "Event.h"
#include "Queue.h"

void simulate(){
PriorityQueue<Event> events;
Queue<Event> bankLine;

//declaring variablesj
int time = 0 , length = 0;
int totalCustomers = 0;
double totalWaitingTime = 0.0;
double averageWaitingTime = 0.0;
int currenttime = 0;
int departuretime = 0;
bool telleravailable = true;

//enqueing into a priority queue to sort the data
while(cin>>time>>length){
    Event a('A',time,length);
    events.enqueue(a);
    totalCustomers++;
}

cout<<"Simulation Begins\n";

//event loop
while(!events.isEmpty()){
Event newEvent = events.peek();

currenttime = newEvent.getTime();
//If the event is of arrival tyoe
if(newEvent.getType() == 'A'){
    events.dequeue();
    Event customer = newEvent;
    if(telleravailable && bankLine.isEmpty()){
        //if the bankline is empty , process the departure event
        departuretime = currenttime + customer.getLength();
        Event d('D',departuretime);
        events.enqueue(d);
        telleravailable = 0;
    }else{
        bankLine.enqueue(customer);
    }
    cout<<"Processing an arrival event at time:\t"<< currenttime<<endl;

}else{
    events.dequeue();
// if the event is departure type
    if(!bankLine.isEmpty()){
        //if the bankline is empty , process the departure event
        Event customer = bankLine.peek();
        bankLine.dequeue();
        departuretime = currenttime + customer.getLength();
        totalWaitingTime += currenttime - customer.getTime(); 
        Event d('D',departuretime);
        events.enqueue(d);
    }else{
        telleravailable = 1;
    }

    cout << "Processing a departure event at time:\t" << currenttime << endl;
}
}
//calculating average wait time
if(totalCustomers!=0)
averageWaitingTime = totalWaitingTime/totalCustomers;


cout<<"Simulation Ends\n\n";
cout<<"Final Statistics:\n\n";
//printing the required values
cout<<"\tTotal number of people processed: "<<totalCustomers <<endl;
cout<<"\tAverage amount of time spent waiting: "<< averageWaitingTime<<endl;
}


int main(){
//calling to simulate
simulate();
cout<<endl;

return 0;
}