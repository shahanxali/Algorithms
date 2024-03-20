#include <iostream>
using namespace std;

void quicksort(int arr[], int size);

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quicksort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void quicksort(int arr[], int size)
{
    if (size <= 1)
        return;

    int pivot = arr[size - 1];
    int leftarr[size], rightarr[size];
    int l = 0, r = 0;

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

    quicksort(leftarr, l);
    quicksort(rightarr, r);

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
}
