//Question: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
//Level: Medium


//This question is solved using DP 2

//This is pretty hard one, know that it uses backtrack solution but gived time limit exceeted for third case only, which is a very bad solutioon.
//So think about it and know that this is solved using dp 2, how so?
//Go to explanation: https://medium.com/tech-life-fun/leet-code-1155-number-of-dice-rolls-with-target-sum-graphical-explained-python3-solution-224f8c0af23
//To form target t, with n dices and k faces, we need to know number of ways to form target - 1, target - 2.... upto target - k using n - 1 dices.
//Why? Think about it, how do you form a number 4 using numbers 1 2 3, 1 2 3, 1 2 3? The way you  can form 3 using 1 2 3, 1 2 3 because thus for last
//1 2 3 we can add 1 in it, and then the way you can form 2 using 1 2 3, 1 2 3 because at last you can add 2 to the target for last  1 2 3
//Getting it? see the article where d is n and f is k and target is target, d(3, 8) means ways to form 8 using 3 dices

//The Recursive formula will help understand it better, so,
//Here n = number of dice, k = number of faces in each dice, t = target
//Formula would be : d(n, t) = (submission i from 1 to target) d(n - 1, t - i);
//Basically d(n, t) = d(n - 1, t - 1) + d(n - 1, t - 2) + d(n - 1, t - 3)...... d(n - 1, t - k)



//Recursive Solution:

class Solution {
public:

    int recur(int n, int k, int target, int ans){


        if (n == 0) {
            return target == 0 ? 1 : 0;
        }
        if(target <= 0){
            return 0;
        }

        ans = 0;
        for(int i = 1; i <= k; i++){
            ans += recur(n - 1, k, target - i, ans);
        }

        return ans % INT_MAX;

    }

    int numRollsToTarget(int n, int k, int target) {
        
        return recur(n, k, target, 0);

    }
};




//Top Down:

class Solution {
public:

    int recur(int n, int k, int target, vector<vector<int>>& dp){


        if (n == 0) {
            return target == 0 ? 1 : 0;
        }
        if(target <= 0){
            return 0;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        int ans = 0;
        for(int i = 1; i <= k; i++){
            ans += recur(n - 1, k, target - i, dp);
            dp[n][target] = ans;
        }

        return dp[n][target] % INT_MAX;

    }

    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return recur(n, k, target, dp);

    }
};


//Bottom Up:

class Solution {
public:
    int recur(int n, int k, int target, vector<vector<int>>& dp) {
        const int MOD = 1e9 + 7;

        // Fill dp array
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                dp[i][j] = 0; // Initialize current cell
                for (int face = 1; face <= k; ++face) {
                    if (j - face >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
                    }
                }
            }
        }
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1; // Base case: 1 way to reach target 0 with 0 dice

        return recur(n, k, target, dp);
    }
};













//First is the backtrack solution which is not right, but se it anyways lol
class Solution {
public:

    //count -> depth. index -> backtrack, ans -> number of ways to return, temp -> temporarily add ans

    void backtrack(int n, int k, int target, int count, int& ans, int temp){

        if(count == n){
            if(temp == target){
                ans++;
            }
            return;
        }

        for(int i = 1; i <= k; i++){
            
            temp += i;
            backtrack(n, k, target, count + 1, ans, temp);
            temp -= i;

        }

        return;
        

    }

    int numRollsToTarget(int n, int k, int target) {
        int ans = 0;

        backtrack(n, k, target, 0, ans, 0);

        return ans;

    }
};








