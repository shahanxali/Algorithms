//Time Complexity: Worst= nlogn, Average= nlogn, Best= nlogn
//Space Complexity: 1

//https://www.geeksforgeeks.org/heap-sort/


//So..., you need to know about heap first before knowing what heapsort do, talking about heaps, Heap is binary tree with insertion from left to right
//like first root, then root's left, then root's right, then root's left's left, so on goes like breadth first search. there is one thing to keep in mind and 
//That is that in heap, the node is greater than the childrens (if it is max heap, other wise ulta in min heap), thats it (remember its different from binary search tree where we see left and right childer, in heap we
//dont see left or right, we see all child should be smaller than or equal to the parent.)
//Now talking about heapsort, what it do is.... make a binary tree from the array, then heapify it (convert the tree into max heap) and then take the uppermost
//element (root) and store it in the array and then change the last leaf and place it in the root, and heapify again and so on untill we reach no elements
//But in the case when we start programming, we will assume that we took a heap, but will only use maths and calculations to do the heapifying and all and all
//because it is possible and doing so will give us in place algorithm
//one thing to remember is that 2*t + 1 will give left node of the parent and 2*t + 2 will give right child.
//We will have two loops, first to overall heapify the array, and then one by one get the top most element and place it at the right position and 
//make the last element the root one and then recall the heapify with the subarray which shouldnt include all those which are already placed



#include<iostream>

using namespace std;

void HeapSort(int* arr, int n);
void heapify(int* arr, int node, int n);
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
    HeapSort(arr, n);
    cout << "The Sorted array is: ";
    PrintArray(arr, n);

    return 0;

}


void heapify(int* arr, int node, int n){

    int left = 2 * node + 1;
    int right = 2 * node + 2;
    int largest = (left < n && arr[left] > arr[node]) ? left : node;
    largest = (right < n && arr[right] > arr[largest]) ? right : largest;

    if(arr[node] != arr[largest]){

        swap(arr[node], arr[largest]);

        heapify(arr, largest, n);

    }

    return;

}

void HeapSort(int* arr, int n){

    for(int i = n / 2; i >= 0; i--){

        heapify(arr, i, n);

    }

    for(int i = n - 1; i > 0; i--){

        swap(arr[i], arr[0]);

        heapify(arr, 0, i);

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
