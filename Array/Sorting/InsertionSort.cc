//Time Complexity: Worst= n^2, Average= n^2, Best= n
//Space Complexity: 1

//Explaination: https://www.geeksforgeeks.org/insertion-sort/


//So here is Insertion Sort, just opposite of Selection Sort, so basically we are just swapping the elements one by one (which you know swap
//only when first is larger than second element, you aint that stupid) so whenever I swap, I just go back with that same swapped element, go back
//one by one and checking that swapped element with previous elements by going back and go back untill that element is at its right position
//like a number will be swapped when it is lower than just before element, and then go back means 2 steps back and check if its smaller than that element too?
//like in  1 3 4 2, when 2 is compared and swapped with 4, then go back again and compare 2 with 3, yeah need to swap and again go back compare with 
//1 now no need to swap so get back to 4 because 2 is in right position now and before 2 is all sorted, think about it.
//so overall we are just taking the element and placing it just after the number smaller than that, sorting ofcourse.


#include<iostream>
using namespace std;

void InsertionSort(int* array, int n);
void PrintArray(const int* array, int n);


int main(){

    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    //for case when n is negative or 0, corner case handled
    if(n<=0){
        cout<<"Invalid input."<<endl;
        return 1;
    }

    //input array
    int arr[n];
    cout<<"Enter the array now: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //calling functions
    InsertionSort(arr, n);
    cout<<"Sorted array: ";
    PrintArray(arr, n);

    return 0;

}


//this is the implementation of Insertion Sort
void InsertionSort(int* array, int n){

    //the first loop to go from 0 to n to check on time ofcoure, we will need to go back whenenever we swap untill we complete the array one time
    for(int i=0; i<n-1; i++){

        //condition of swapping and whenever first element is greater than second
        if(array[i]>array[i+1]){
            int temp=array[i];
            array[i]=array[i+1];
            array[i+1]=temp;

            //this loop is in the if condition of swapping because we need to call it only when we swapped
            //because when we swap, we know that number is not in right position, so we go back by this loop 
            //and check and swap all the time, and while going back if we find no swap need then break the loop
            //think hard and imagine, you will go back untill no need to swap because when no need to swap that means
            //it is in right position now(sorted till now)
            for(int j=i; j>0; j--){

                //swapping
                if(array[j-1]>array[j]){
                    int temp2=array[j];
                    array[j]=array[j-1];
                    array[j-1]=temp2;
                }
                //and if no swapping then break the loop because no need to go more back
                else{
                    break;
                }

            } 
        }

    }
    
    //blah blah blah
    return;

}

//printing the array
void PrintArray(const int* array, int n){

    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    return;

}