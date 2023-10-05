//Time Complexity: Worst= n^2, Average= n^2, Best= n^2
//Space Complexity: 1

//Explaination: https://www.geeksforgeeks.org/selection-sort/


//We basically have to check smallest number in the array first and then place it in the first place,
//then take second smallest and get it to the second place and so on to the last
//so what I did was just take first element and make loop from first to last to check if we have lowest element where
//and swap the first element with the lowest found
//then do it with second element, take the second one and go loop from second to last comparing each element and getting the lowest till now from second to last this time
//and then wherever found, swap with the second element. Then with the third.
//do it till the end, now see the main function to know how it implemented on code.

#include <iostream>
using namespace std;

void SelectionSort(int* array,int n);
void PrintArray(int* array, int n);


int main(){

    int n;
    cout<<"enter number of elements in the array: ";
    cin>>n;
    
    //for special case when n have value less then or equal to 0
    if (n <= 0) {
        cout << "Invalid array size. Exiting." << endl;
        return 1;
    }

    //taking the input
    int arr[n];
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //calling functions
    SelectionSort(arr,n);
    PrintArray(arr,n);

    return 0;

}



//this is where it is implemented, watch this function to know Selection Sort
void SelectionSort(int *array, int n){

    //first loop to go from first to last one time
    for(int i=0;i<n;i++){
        //this is because we want to get smallest value from i to last, then we have to initialize an integer with something
        int small=i;

        //second loop in it to check each element from i+1 (because we already have ith value in small) that which is lowest so we can swap with ith element
        for(int j=i+1;j<n;j++){
            //check if current element is lower than small we got so far?, if so then that lower will be small ofcourse
            if(array[j]<array[small]){
                small=j;
            }
        }

        //we got lowest element "small" till now from i to n, we now have to swap it with i,
        //the i will have smallest if i is 0, second smallest if i is 1 and so on, think about it 
        int temp=array[i];
        array[i]=array[small];
        array[small]=temp;

    }

    return;

}

//Print the array, no need to explain this. just so basic thing lmao
void PrintArray(int* array, int n){

    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return;

}