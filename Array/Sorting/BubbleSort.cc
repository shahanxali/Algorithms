//Time Complexity: Worst= n^2, Average= n^2, Best= n
//Space Complexity: 1

//Explaination: https://www.geeksforgeeks.org/bubble-sort/


//So here is like the easiest sorting method to understand, we simply just comparing first and second element and if first is greater than 
//second then swap them ofcourse, then second and third element, then fourth and 5th element to the end and doing this untill our array is 
//sorted, like till the end swap and all, then go to the first and start over again.
//And if you think about it, the last element will be greatest in first time swapping to last, then second last element is greater, its jsut like 
//opposite of selection sort where the first element is smallest then second, here the last element is largest and then second last and so one, you
//get me? no then go to the 4th line link to get visually. 
//compare the first two elements and swap if first is greater, then compare the second two elements and so one, and then start over again
//and the second time you are starting, you just dont need to include the last element as it is already at right position
//and do this till you get to first (meaning that last is greatest, then second last is second greatest which is not be included when going to the 3rd round) 


#include<iostream>
using namespace std;

void BubbleSort(int* array, int n);
void PrintArray(int* array, int n);

int main(){

    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;

    //for special case when n have value less then or equal to 0
    if (n <= 0) {
        cout << "Invalid array size. Exiting." << endl;
        return 1;
    }

    //taking inputs
    int arr[n];
    cout<<"Enter the Array now: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //calling functions
    BubbleSort(arr, n);

    cout<<"Sorted Array: ";
    PrintArray(arr, n);

    return 0;

}

//this is the function to implement bubble sort so...
void BubbleSort(int* array, int n){

    //the first loop goes to the end saying the number of times you should go as round, like swap till last then round 2 swap till second last and round 3 etc
    for(int i=0;i<n;i++){

        //this bool is for the case when we get sorted elements in the array at the previous round, think about it, this will be false till
        //last and if it is false then ofcourse the array is sorted, and it will get true if we get to swap the elements, and if true
        //then it means we had to swap, and if we had to swap then no need to break go for it.
        bool swapped=false;

        //this is for going till last comparing all consecutive elements, then go till second last, then go till third last, thats why n-i, and
        //and we have to compare first to second elements na, what if we get to last and then i+1 comparison will make not sense as it will go overflow
        //so we will go n-i-1 every round.
        for(int j=0;j<n-i-1;j++){

            //this is the comparison, if you read all the comments then you know if first is greater than second then swap them, and donr forget swapped boolean value 
            //to be true everytime we swap.
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                swapped=true;
            }

        }

        //if swapped is true that means if there is a swap in previous round then we shouldnt break the loop and if there was no swap, then we dont 
        //need to go another round because the array is sorted then, worst case will be it always be true untill the last possible round.
        if(!swapped){
            break;
        }
    }

    return;

}


// I shouldnt be explaining this one cause neither me nor you are stupid at this point lol.
void PrintArray(int* array, int n){

    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }

    cout<<endl;

    return;

}