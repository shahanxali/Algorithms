//Time Complexity: Worst= nlogn, Average= nlogn, Best= nlogn
//Space Complexity: n

//Explaination: https://www.geeksforgeeks.org/selection-sort/



#include<bits/stdc++.h>
using namespace std;

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
    MergeSort(arr, n);
    cout << "The Sorted array is: ";
    PrintArray(arr, n);

    return 0;

}

int MergeSort(int* arr, int n){

    

}