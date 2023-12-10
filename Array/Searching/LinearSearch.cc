//Time Complexity: Worst- O(n), Average- O(n), Best- O(1)
//Space Complexity: O(1)

//Explanation: If you need to see this then give up engineering


#include<iostream>
using namespace std;

int linearsearch(int* arr, int n, int element);


int main(){

    //Taking input and creating the array
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array now: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //taking input of element we want to search for in the array
    int element;
    cout<<"Enter the element you wanna find: ";
    cin>>element;

    int index = linearsearch(arr, n, element);

    if(index != -1){
        cout<<"Found element at position: " << index + 1;
    }

    else{
        cout<<"Not found";
    }



}


int linearsearch(int* arr, int n, int element){

    for(int i=0; i<n; i++){
        if(arr[i] == element){
            return i;
        }
    }

    return -1;

}
