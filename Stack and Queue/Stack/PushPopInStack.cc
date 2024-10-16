//Time Complexities: Push- O(1) Pop- O(1)
//Space Complexities: Push- O(1) Pop- O(1)

//Explanation: https://www.geeksforgeeks.org/time-and-space-complexity-analysis-of-stack-operations/

//So we are here in stack, with Push and Pop operations, basically a stack works in LIFO that is first in last out method.
//which means whatever gone in last will be out first. just like stack of plates. Now Push means adding the element and Pop means deleting the element.
//we created a menu and thus a stack using array and asked if user want to push or pop. We are taking an integer named top to be aware of current index
//of the stack that is the element last inned or outed.
//So in PUSH we did add the element the array in the position top we are keeping track of and ogcourse increasing top by one bececause then top will be changed
//And in POP we just decreased the top index because we cant delete in an array, we just have to change the index and range and thats what we did.

#include<iostream>
using namespace std;

const int max_size = 100; // Define the maximum size of the stack

int top = -1; //to keep track of current index starting from -1 because initially no index needed

void push(int* stack, int element);
void pop(int* stack);
void printstack(int* stack);

int main() {

    //array to store stack
    int stack[max_size];

    // Creating a menu
    bool running = true;


    while (running) {
        cout << "Enter the operation you want to do, 1 for Push, 2 for Pop, 3 to exit: ";
        int choice;
        cin >> choice;

        // PUSH
        if (choice == 1) {
            cout << "Enter the value of the element: ";
            int element;
            cin >> element;
            push(stack, element);
        }

        // POP
        else if (choice == 2) {
            pop(stack);
        }

        // EXIT
        else if (choice == 3) {
            running = false;
        }

        // Error handling
        else {
            cout << "Enter a valid number. Exiting!" << endl;
            running=false;
        }

        //Always printing the stack whenever we do any operation or chose anything menu options
        printstack(stack);
    }

    return 0;
}


//Push operation which handles overflow that is the maximum size of the array that is stack.
//And then increasing the top to keep track of the current index first, at first time this top will be 0 and putting element in top of array
//that is 0 index at first. Now anytime this push is called the top will be increased the top index of array will be put as the element we wanna push
void push(int* stack, int element) {
    // Overflow handling
    if (top >= max_size - 1) {
        cout << "Stack Overflow" << endl;
    } 
    else {
        top++;
        stack[top] = element;
    }

    return;
}


//This is pop operation and we just handeled the situation if the array is empty that is underflow
//and just decreasing the top that is current index whichi will ignore the element we want to pop but not delete it
//do deleting because we cant in array.
void pop(int* stack) {
    // Underflow handling
    if (top < 0) {
        cout << "Stack Underflow" << endl;
    } 
    else {
        top--;
    }

    return;
}


//Printing the array aka stack
void printstack(int* stack) {
    cout << "The stack is: ";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;

    return;
}
