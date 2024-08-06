//Time Complexity: Worst- O(log n), Average- O(log n), Best- O(1)
//Space Complexity: O(1)

//Explanation: SO what we tryna do is this, we will find the element in the sorted array only, if not a sorted array, this will not work
//We took a mid value and checked if middle of the array is larger or smaller or just equal to the element we wanna find
//if the mid one is larger that means the element we wanna find lies before the mid, so call the function again but take the
//subarray with elements 0 to mid, means the first half of the element to check for its middle again and repeat
//same when if mid is smaller than element to find call the function again and this time call for sub array of second half
//then do this untill you get mid el array equal to the element you wanna find. and if it is equal, just leave the function with mid


#include<iostream>
using namespace std;


int BinarySearch(int* arr, int n, int a, int min, int max);


//main function
int main(){

    // Input taking
    int n;
    cout<<"Enter the number of elements of your array: ";
    cin>>n;

    //Sorted order only
    int arr[n];
    cout<<"Enter the SORTED array now: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int a;
    cout<<"Enter the number you wanna find: ";
    cin>>a;

    int found = BinarySearch(arr, n, a, 0, n - 1);

    // Found
    if(found != -1){
        cout<<"Found element at position: "<<found + 1<<endl;
    }
    //Did not find the element
    else{ 
        cout<<"Couldn't find element"<<endl;
    }


    return 0;
}


//This is the function of Binary Search
//We have min, to take first element of every sub array, max to take the last element of that sub array we wanna be called the function again
int BinarySearch(int* arr, int n, int a, int min, int max){

    // Check if the base case is reached
    if (min > max) {
        return -1;  // Element not found
    }


    // Find middle index
    int mid = (min + max) / 2;

    //Element found case
    if(arr[mid] == a){
        return mid;  // Element found, return the mid which is the index
    }

    // If mid is smaller than the searching element
    else if(arr[mid] < a){
        return BinarySearch(arr, n, a, mid + 1, max);  // Search in the right half
    }

    // If mid is greater than the searching element
    else {
        return BinarySearch(arr, n, a, min, mid - 1);  // Search in the left half
    }
    
}
