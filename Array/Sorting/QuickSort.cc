//Time Complexity: Worst= n^2, Average= nlogn, Best= nlogn
//Space Complexity: n

//Explaination: https://www.geeksforgeeks.org/quick-sort/


//So starts the tricky one, we are basically chosing a fixed position known as pivot, chose whatever position you like, i chose the last one, that is 
//n-1 th postion as pivot at first, and then compare each and every element and whichever is lower, put that before pivot, and whichever is greater
//put that after the pivot, that way you will have all lower than pivot before pivot and all higher than pivot at after the pivot, thats how you change 
//the position of pivot to better place from the last. Now in the second round we gonna do the same for both before the pivot subarray as well ass after the pivot subarray
//and thus used recursion to call that same function for subarray before pivot, chosing pivot as pivot again and after of pivot subarray will have pivot as last element
//of the subarray and do so untill we get to the smallest digit 1 that is pivot is the starting element.
//thats how you do quick sort, you can imagine it like pivot getting to almost in the middle and then in second round two subarrays (before pivot, after pivot)
//have 2 pivots and areange it and then subarrays of subarrays formed and so on till the first element. 


#include<iostream>
using namespace std;

void QuickSort(int* array, int start, int end);
void PrintArray(const int* array, int n);

int main() {

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
    QuickSort(arr, 0, n - 1);
    cout << "The Sorted array is: ";
    PrintArray(arr, n);

    return 0;

}

//The implementation of quick sort is in this function ofcourse
void QuickSort(int* array, int start, int end) {

    //running till we get end = start, that is when we want to break the recursion and found the answer
    if (start < end) {

        //pivot is chosed to be end, see not the last because we have to call the function again and again and whenever called the function we can
        //choose pivot to be end but the value of n will be same na
        int pivot = end;

        //to track the element larger than pivot in each recursion (for placing the greater elements after pivot)
        int i = start - 1;

        //loop to just place elements respective to pivot, the logic is easy if you think about it, keeping track of larger elements and then swapping
        //its just a little confusing but if you design the logic for swapping such a way you will get to this loop eventually
        for (int j = start; j < end; j++) {
            if (array[j] < array[pivot]) {
                i++;
                swap(array[i], array[j]);
            }
        }

        //at the end place the pivot at the position it should be and that would be last swapped element cause that would be the smallest larger element of pivot
        swap(array[i + 1], array[pivot]);

        //recursion call for array starting from start to i that is one less then pivot to
        QuickSort(array, start, i);

        //recursion call for array starting from i+2 that is one larger than pivot to the end
        QuickSort(array, i + 2, end); 

        //these two recursion will go on till the last while changing the start, end, i with need 

    }

    return;
}


//again with this printing thing, damn easy
void PrintArray(const int* array, int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";

    return;
}
