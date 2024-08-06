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

void quicksort(int arr[], int size);
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
    quicksort(arr,n);
    cout << "The Sorted array is: ";
    PrintArray(arr, n);

    return 0;

}

//The implementation of quick sort is in this function ofcourse
void quicksort(int arr[], int size)
{

    //Base case of the Quick Sort recursion or we can say backtracking, if the sub arrays gets to 1 size, that means
    //we need to no join the array right? like split split split till? ofcourse unless you are to the array of size 1
    //That is the last splitting and then we gotta merge
    if (size <= 1)
        return;


    //From here we got to create two arrays, left and right, left will be all smaller than pivot and right will be all greater
    //Nothing new, as the first step to split right? all as it should be!

    //pivot chosen as last of the array
    int pivot = arr[size - 1];
    int leftarr[size], rightarr[size];
    //To keep track of indexes top insert in left and right subarrays
    int l = 0, r = 0;

    //2 different loops to do that placing of elements from original array to the left and right sub array
    //read the code carefully and you will know how we doing it
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] <= pivot)
        {
            leftarr[l] = arr[i];
            l++;
        }
        else
        {
            rightarr[r] = arr[i];
            r++;
        }
    }

    //Here is the main part, we are gonna call left sub array and do that splitting (done in previous lines) and create left and 
    //right subarrays for that too and then again call to the last unless the base case is met that is the element is 
    //only 1 left
    quicksort(leftarr, l);
    //And splitting all that rights of all left subarrays you know, splitting with condition all the time creating all that left
    // and right with conditions and splitting
    quicksort(rightarr, r);

    //Now all the sub arrays gonna go back to the original one which so we need to write all left and right ones sub arrays into
    //this arr array which would be need in the main program, to print ofcourse.
    int index = 0;
    for (int i = 0; i < l; i++)
    {
        arr[index++] = leftarr[i];
    }
    arr[index++] = pivot;
    for (int i = 0; i < r; i++)
    {
        arr[index++] = rightarr[i];
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
