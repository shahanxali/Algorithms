//Time Complexity: Worst= n + k, Average= n + k, Best= n + k    (k is the range of the key value that is if array have 0 to 100 numbers then k is 100)
//Space Complexity: n + k

// https://www.geeksforgeeks.org/counting-sort/


//So comes the Counting sort which is a stable sorting technique, its easier than other devide and rule methods of sorting, becuase its just a couple of loops
//and thats it, just the algorithm is enough to understand and you will code it right away. So basically what we do here is firstly find the maximum element of the array
//call it max, now create another array with max's range, call it countarr, the countarr lenght is max, which will store the number of occurence of the element
//original array (arr), we will take each element of arr and will increase the number of countarr of that position, like for example if arr have {1,2,1}
//then countarr will have 2 in first position and 1 in second position becaus 1 is 2 times and 2 is one time, getting it? take a look at the gfg link and check
//how it store the numbers to get a good grip, like till now if we take an example, arr = {3.3.3.5.1} so the countarr will be {1,0,3,0,1} which stores thr occurance yk
//Next what we will do is that, find the cumulative sum of the countarr, (cumulative sum means how many steps total till now, like cumulative sum of 1,2,3,4 is 
// 1,3,6,10 which is 1, 1+2, 1+2+3, 1+2+3+4) this will give how many steps should i go further while forming the original array from countarr
//Now take another array name it ans, take each element of arr, check the number of countarr and fill that number into ans, imagine it or check in the gfg,
//The photoes will make you understand better because we are playing with 3 arrays. 
//That's it copy the ans into arr to make it like, not use more array in the end yk, space things.







#include<iostream>
#include<vector>

using namespace std;

void CountingSort(int* arr, int n);
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
    CountingSort(arr, n);
    cout << "The Sorted array is: ";
    PrintArray(arr, n);

    return 0;

}


void CountingSort(int* arr, int n){

    //Finding the max
    int max = arr[0];
    for(int i = 1; i < n; i++){ // Start from index 1
        if(arr[i] > max){
            max = arr[i];
        }
    }

    //Create the array of max + 1 elements
    int countarr[max + 1];
    for(int i = 0; i <= max; i++){ // Initialize all elements to 0
        countarr[i] = 0;
    }

    //Applying each number's counting to it
    for(int i = 0; i < n; i++){
        countarr[arr[i]]++;
    }

    //Do the cumulative sum
    for(int i = 1; i <= max; i++){ // Start from index 1
        countarr[i] += countarr[i - 1];
    }

    //refilling the array
    int ans[n];
    for(int i = 0; i < n; i++){ // Traverse the array from end to start
        int index = countarr[arr[i]] - 1;
        ans[index] = arr[i]; // Place the element at correct position in ans array
        countarr[arr[i]]--;
    }
    
    // Copy the sorted array back to original array
    for(int i = 0; i < n; i++){
        arr[i] = ans[i];
    }
}


//again with this printing thing, damn easy
void PrintArray(const int* array, int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";

    return;
}
