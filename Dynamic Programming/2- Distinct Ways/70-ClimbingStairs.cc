//Question: https://leetcode.com/problems/climbing-stairs/
//Level: Easy


//The Question is solved using DP 2


//Just think about it, it is basically fibonnaci series only lol. Number of ways to reach a point would be numbe of ways to 
//reach previous one + number of ways to previous second. KNOW that it is number of ways, it is different for all previous even if patterns repeat



//Recursive Solution:

class Solution {
public:

    int recur(int n){

        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }

        int fin = recur(n - 1) + recur(n - 2);

        return fin;
        
    }

    int climbStairs(int n) {
        
        return recur(n);

    }
};





//Top Down:


class Solution {
public:

    int recur(int n, vector<int>& dp){

        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = recur(n - 1, dp) + recur(n - 2, dp);

        return dp[n];
        
    }

    int climbStairs(int n) {
        
        vector<int> dp(n + 1, -1);
        return recur(n, dp);

    }
};




//Bottom Up:

class Solution {
public:

    int recur(int n, vector<int>& dp){

        dp[1] = 1;
        dp[2] = 2;

        
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }


        return dp[n];
        
    }

    int climbStairs(int n) {
        
        vector<int> dp(n + 1, -1);
        return recur(n, dp);

    }
};






//Space Optimization:



class Solution {
public:

    int recur(int n){

        if(n <= 2){
            return n;
        }

        int a = 1;
        int b = 2;
        int c = 0;
        
        for(int i = 3; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }


        return c;
        
    }

    int climbStairs(int n) {
        
        return recur(n);

    }
};
