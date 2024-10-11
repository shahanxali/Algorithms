//Question: https://leetcode.com/problems/perfect-squares/?envType=problem-list-v2&envId=55ac4kuc
//Level: Medium

//THIS QUESTION IS SOLVED USING DP 1
//The problem was in converting memoized top down to bottom up
//The top down appraoch toom 2^n time while bottom up took n*root(n)



//Recursion:

class Solution {
public:

    bool ispr(int n){
        int a = sqrt(n);
        return a * a == n;
    }

    int dp(int n){

        if(ispr(n)) return 1;


        int ans = INT_MAX;

        for(int i = 1; i < n; i++){
            ans = min(ans, dp(n - i) + dp(i));
        }

        return ans;

    }

    int numSquares(int n) {

        return dp(n);

    }
};



//Memoized (Top Down):

class Solution {
public:

    bool ispr(int n){
        int a = sqrt(n);
        return a * a == n;
    }

    int dp(int n, vector<int> memo){

        if(ispr(n)) return 1;

        if(memo[n] != -1) return memo[n];

        int ans = INT_MAX;

        for(int i = 1; i < n; i++){
            ans = min(ans, dp(n - i, memo) + dp(i, memo));
        }

        return memo[n] = ans;

    }

    int numSquares(int n) {
        vector<int> memo(n + 1, -1);

        return dp(n, memo);

    }
};


//Bottom Up:

class Solution {
public:

    bool ispr(int n){
        int a = sqrt(n);
        return a * a == n;
    }

    int dp(int n, vector<int> memo){

        if(ispr(n)) return 1;
        memo[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sqrt(i); j++){

                int jsq = j * j;
                memo[i] = min(memo[i], memo[i - jsq] + 1);

            }
        }

        return memo[n];

    }

    int numSquares(int n) {

        vector<int> memo(n + 1, INT_MAX);

        return dp(n, memo);

    }
};
