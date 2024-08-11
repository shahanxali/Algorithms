//Question: 
//Level: Medium


//THE QUESTION IS SOLVED USING DP 1



//Recursive solution:

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0){
            return 0;
        }

        int ans = INT_MAX;

        for(int i = 0; i < coins.size(); i++){

            
            if(coins[i] <= amount){
                int t = coinChange(coins, amount - coins[i]);
                if(t != -1)
                    ans = min(ans, t + 1);
            }

        }

        return ans == INT_MAX ? -1 : ans;

    }
};



//Top Down Approach

class Solution {
public:

    int recur(vector<int> coins, int amount, vector<int> &dp) {
        if(amount == 0) {
            return 0;  // Base case: no coins needed to make amount 0
        }

        if(dp[amount] != INT_MAX) {
            return dp[amount];  // Return already computed result
        }

        int ans = INT_MAX;

        for(int i = 0; i < coins.size(); i++) {
            if(coins[i] <= amount) {
                int t = recur(coins, amount - coins[i], dp);
                if(t != -1) {
                    ans = min(ans, t + 1);
                }
            }
        }

        dp[amount] = (ans == INT_MAX) ? -1 : ans;  // Memoize the result
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);  // Initialize memoization table
        return recur(coins, amount, dp);
    }
};




//Bottom Up:

