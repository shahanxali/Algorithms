//Time Complexity: Worst= n + k, Average= n + k, Best= n + k    (k is the range of the key value that is if array have 0 to 100 numbers then k is 100)
//Space Complexity: n + k

// https://www.geeksforgeeks.org/radix-sort/








#include<iostream>

using namespace std;

void RadixSort(int* arr, int n);
void PrintArray(const int* array, int n);

int main(){

    //input things
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    //for corner case when n is smaller than or equal to 0
    if (n <= 0) {
        cout << "Invalid Input. " << endl;
        return 1;
    }

    //input array
    int arr[n];
    cout << "Enter the array now: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //calling the sorting function and printing of array
    RadixSort(arr, n);
    cout << "The Sorted array is: ";
    PrintArray(arr, n);

    return 0;

}



void RadixSort(int* arr, int n){


    for(int i = 0; i < n; i++){

        

    }


}

//how about i just leave it, what will you see then lmao?
void PrintArray(const int* array, int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";

    return;
}


