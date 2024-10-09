//Boyer Moore's majority voting algorithm
//Time complexity: O(n), Space: O(1)
//Explanation: https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/


//Boyer Moore's Algorithm is used to find a element which is of more than n/2 occurrence using majority voting
//Speciality of this algorithm is that it takes n time complexity and constant space

//Basic idea is to go in for loop, taking current element and giving votes to it as per the loop goes, increamenting when the
//same number comes and decrementing when diffenet number comes

//How it works? initialize candidate as -1, vote as 0
//Go throughout the array, at arr[0], take candidate = arr[0] and increase vote, then go further
//When arr[i] is same as candidate, then increase vote and if arr[i] is not equal to candidate then decrease vote
//Once vote is 0, then considerr arr[i] as candidate from now on taking vote = 1 and so on
//at last we will have a candidate value, now take another loop to confirm if the candidate is equal to or greater than n/2
//and if so then boom, print it


#include<bits/stdc++.h>
using namespace std;

int boyermoore(vector<int> arr){

    int candidate = -1, vote = 0;

    for(int i = 0; i < arr.size(); i++){
        if(vote == 0) candidate = arr[i];
        if(arr[i] == candidate) vote++;
        else vote--;
    }

    int check = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == candidate) check++;
    }

    if(check >= (arr.size() / 2)) return candidate;
    return -1;

}

int main(){

    vector<int> arr = {2,1,9,3,3,1,9,9,6,1,9,9,9,9,5,4,1,9,9,9,9,9,9,9,1,3,3,1,1,9,9,9,9,9,9};

    cout << boyermoore(arr) << endl;

    return 0;

}
