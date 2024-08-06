//Time Complexity: Worst= nlogn, Average= nlogn, Best= nlogn
//Space Complexity: n

//Explaination: https://www.programiz.com/dsa/merge-sort


//So here, like quicksort, we are gonna partition the array into sub arrays in left and right, but without condition, that is only
//just break down the array to the last element thats it, now the main part is merging, quicksort breaks the part in such a way that
//we just need to merge last right? the opposite is merge sort, we breaks the array to the last and THEN we merge the arrays such a way
//that merged subarray is sorted one, and this will include placing the broken elements at right order when merged
//Now the thing is we will merge while sorting the sub array and eventually at the end we will be merging the two sub arrays
//which gonna eventually end up sorted thats it! we just have to go backtrack thing yk, two nodes deviding it in the subarrays
//left and right and at last create logic to merge arrays (placing elements sorted order)
//Note one thing about merging, the sub arrays will be like sorted when partitioned, at first step the elements will be one so 
//we will use two pointers to place one by one in bigger array and the second step, the sub arrays we gonna combine will be 
//already sorted so we can use n time complexity(one loop) to do so, just merge





#include<bits/stdc++.h>
using namespace std;

MergeSort(int[] arr, int size);


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


void mergesort(int arr[], int n)
{
    if (n <= 1)
        return;


    int leftarr[n], rightarr[n];
    int l = 0;
    int r = 0;

    for(int i = 0; i < n; i++){
        if(i < (n / 2)){
            leftarr[l] = arr[i];
            l++;
        }
        else{
            rightarr[r] = arr[i];
            r++;
        }
    }



    mergesort(leftarr, l);
    mergesort(rightarr, r);


    int first = 0, second = 0, orig = 0;

    while(first < l && second < r){

        if(leftarr[first] < rightarr[second]){
            arr[orig] = leftarr[first];
            first++;
            orig++;
        }
        else{
            arr[orig] = rightarr[second];
            second++;
            orig++;
        }


    }
    while (first < l)
    {
        arr[orig] = leftarr[first];
        first++;
        orig++;
    }

    while (second < r)
    {
        arr[orig] = rightarr[second];
        second++;
        orig++;
    }


    return;



}
