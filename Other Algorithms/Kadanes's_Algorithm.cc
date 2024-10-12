//Time Complexity: n
//Space Complexity: 1

//Explanatino: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
//Did not see any better even though its not upto expectations either

//Do line hai ratlo code
//Very nice and famous to find number which is maximum of all sum of subarrays in a array
//The naive approach would just give n^2 complexity which is not good
//Here in Kadane's algorithm it states that you should keep on going storing ans as the largest value till now
//But for subarrays, we can go on, if the negative value comes, consider it too, and subtract with previous calculated value
//Until it turns 0, when it happens that means we shoould keep considering i as new subaaray's start
//Basically just checking maximum of (prev + arr[i], arr[i]), think about it I know its hard that's why asked to just learn
//keeping that value to obviously prev + arr[i] will give max value but up to when? when the next arr[i] value will give negative
//that will lead you to consider a new subarray from now on
//Imagine it as you are going in an array, and how you will calculate the maximum sub array till now, whatever the number comes you will just
//keep onn increasing or decreasing it with whatever you have calculated till now
//IN ALL OF THIS the ans is being stores independently, and at the end return the ans




#include<bits/stdc++.h>
using namespace std;

int kadanes(vector<int> arr){

    //Obviously it all starts with first index, it will be the answer for now ans it should be taken to consider till now (starting)
    int curr = arr[0];
    int ans = arr[0];

    for(int i = 1; i < arr.size(); i++){

        //The main part where it all happens
        curr = max(curr + arr[i], arr[i]);

        //To keep on storing the answer, no change anyways
        ans = max(ans, curr);

    }

    return ans;

}

int main(){

    vector<int> arr = {1,2,4,0,-2,8,-1,-2,7,6,8,12,-10,-3,0,-2,1};

    cout << kadanes(arr) << endl;

    return 1;


}











//Naive approach

// #include<bits/stdc++.h>
// using namespace std;

// int kadanes(vector<int> arr){

//     int count = 0, ans = INT_MIN, a, b;
//     vector<int> temp;

//     for(int i = 0; i < arr.size() - 1; i++){
//         count = 0;
//         for(int j = i; j < arr.size(); j++){

//             count += arr[j];

//             ans = max(ans, count);

//         }

//     }
//     return ans;


// }

// int main(){

//     vector<int> arr = {1,2,4,0,-2,8,-1,-2,7,6,8,12,-10,-3,0,-2,1};

//     cout << kadanes(arr) << endl;

//     return 1;


// }
