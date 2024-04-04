#include <iostream>
using namespace std;

void heapsort(int arr[], int size);

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    heapsort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void heapsort(int arr[], int n)
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
