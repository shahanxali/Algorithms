//Time Complexity: Worst- O(1), Average- O(1), Best- O(1)
//Space Complexity: O(1)

//Exaplanation: https://www.programiz.com/dsa/queue

//So Queue is like the array in FIFO order that is First in First out order, whatever was the first got in the array must leave first too.
//Its like a pipe, or line of student where whover came first and got in front will leave first and that is FIFO.
//Now Enqueue is adding the element and Dequeue is deleting the element from the Queue it is that simple, its just like push and pop in stack
//but yeah we have to delete from front and add to back, imagine line of student, we gotta add to back and delete to front right?
//So what we actually did was take index of front and back and keeping track of it while changing it as needed, the front named front and back named rear
//The rear will get along with the elements getting added and front will get along with deleting elements.



#include<iostream>
using namespace std;

#define max_size 1000

int front = -1; //front where the element will be deleted
int rear = -1; //rear which is back where element is added


void enqueue(int* queue,int element);
void dequeue(int* queue);
void printqueue(const int* queue);


int main(){

    //array to store Queue
    int queue[max_size];

    // Creating a menu
    bool running = true;


    while (running) {
        cout << "Enter the operation you want to do, 1 for Enqueue, 2 for Dequeue, 3 to exit: ";
        int choice;
        cin >> choice;

        // ENQUEUE
        if (choice == 1) {
            cout << "Enter the value of the element: ";
            int element;
            cin >> element;
            enqueue(queue, element);
        }

        // DEQUEUE
        else if (choice == 2) {
            dequeue(queue);
        }

        // EXIT
        else if (choice == 3) {
            running = false;
        }

        // Error handling
        else {
            cout << "Enter a valid number. Exiting!" << endl;
            running = false;
        }

        //Always printing the queue whenever we do any operation or chose anything menu options
        printqueue(queue);
    }

    return 0;

}


//This is the implementation of enqueue, we just increased the value of rear and putted element at rear position
//like in first go the rear will become 0 and the value is added to 0 then the rear will become 1 and the value will be putted to index 1 of array
void enqueue(int* queue, int element){

    //error handeling when the size is full that is the queue reaches the max size it was defined
    if(rear == max_size){
        cout<<"The Queue is overloaded";
    }
    //real thing
    else{
        rear++; //increasing first so that the index must be kept noted to add any further
        queue[rear]=element; //value is assigned, at 0 in first time, at 1 in second time
    }

    return;

}

//This is the implementation of Dequeue that is deleting the element, we are just increasing the value of front and thats it
//ignoring the elements in the previous front, so when queue is printed, we just start from front
void dequeue(int* queue){

    //error handeling when there is nothing to delete 
    if(front == max_size){
        cout<<"No element to delete.";
    }
    //real thing
    else{
        front++; //increasing the front which ignored the element at first position of the array
    }

    return;

}

//Printing the queue, so at the end after deletion and insertion of element, the queue will be starting from front and will end to rear right
//so we printing the element from front to the rear
void printqueue(const int* queue){

    cout<<"The queue is: ";
    //printing the queue which will have starting from front and ending to the rear
    for(int i=front+1; i<=rear; i++){ //including rear and front's + 1 as first because of array indexing you can think about it why
        cout<<queue[i]<<" ";
    }
    cout<<"\n";

    return;

}