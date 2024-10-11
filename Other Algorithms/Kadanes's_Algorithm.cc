#include<bits/stdc++.h>
using namespace std;

int kadanes(vector<int> arr){



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
