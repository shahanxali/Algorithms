//Time Complexity: Worst= n + k, Average= n + k, Best= n + k    (k is the range of the key value that is if array have 0 to 100 numbers then k is 100)
//Space Complexity: n + k

// https://www.geeksforgeeks.org/radix-sort/


//So here we go, this one is easy to understand but a little challengin or you can say boring to apply, So in this we basically take each digits of every number
//And sort on the basis of that digit and then take another digit and so on. In simple words let me tell you. we have 21 34 52, here first we will sort on the basis
//of unit's digit that is 1 4 2, this will become array 21, 52, 34 and then we will sort on the basis of second's digit which ar 2 5 3 and will become 21, 34, 52
//So this is basics, now for the code, What we need to do is take the biggest number, because it will have maximum number of digits in it, that will be taken to count
//one by one to sort, count 10 as first (unit's) digit and take counting sort to sort basic of unit digit only, now get second's digit and take 100 and this will % 100 and
//will give second's digit of every element, sort on that basis, do it until we reach the maximum limit and thus our array is sorteddd.
//Example will be like 21, 34, 123, 5 here we have 123 which will tell us that 100 is the limit to reach, now sort basis of unit digit then second's digit 
//and then third and then leave and our array will be sorted.






#include<iostream>

using namespace std;

//This Radix sort needs some other sorting technique to work on, so here we will be using Counting sort
void CountingSort(int* arr, int n, int exp);
void RadixSort(int* arr, int n);
void PrintArray(const int* array, int n);

int main(){

    //Do I even have to explain all this?
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid Input. " << endl;
        return 1;
    }

    int arr[n];
    cout << "Enter the array now: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //Here is where the Radix Sort is called
    RadixSort(arr, n);
    cout << "The Sorted array is: ";
    PrintArray(arr, n);

    return 0;

}


//Counting sort, to be called in Radix Sort

void CountingSort(int* arr, int n, int exp){

    int countarr[10] = {0};

    for(int i = 0; i < n; i++){
        countarr[(arr[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; i++){
        countarr[i] += countarr[i - 1];
    }

    int ans[n];
    for(int i = n - 1; i >= 0; i--){
        int index = (arr[i] / exp) % 10;
        ans[countarr[index] - 1] = arr[i];
        countarr[index]--;
    }

    for(int i = 0; i < n; i++){
        arr[i] = ans[i];
    }
}


//Radix Sort is here

void RadixSort(int* arr, int n){

    int maxi = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }

    for (int exp = 1; maxi / exp > 0; exp *= 10) {
        CountingSort(arr, n, exp);
    }
}


//So this is where the sorted array is printed lol

void PrintArray(const int* array, int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}
