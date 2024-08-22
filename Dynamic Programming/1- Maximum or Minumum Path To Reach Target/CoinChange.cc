//Question: https://leetcode.com/problems/coin-change/
//Level: Medium


//THE QUESTION IS SOLVED USING DP 1


//This is pretty hard as you will not find any sequance like before, sequantial go, no, its pretty much like you need to 
//design a logic for recursive solution and find at what sequence is this going, then the problem would be in dp vector
//but no problem, we will do something about it too. So here what we did is just call recursion for each i in amount where if taken
//I in to account, what should be left, you can see the code for better understanding, see the anount part call in recursion call and
//you will know what is going on.


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


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;  // Base case: no coins needed to make amount 0

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    if (dp[i - coin] != INT_MAX) {
                        dp[i] = min(dp[i], dp[i - coin] + 1);
                    }
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};




