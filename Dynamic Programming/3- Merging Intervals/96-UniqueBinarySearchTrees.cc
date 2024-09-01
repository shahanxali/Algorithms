//Question: https://leetcode.com/problems/unique-binary-search-trees/description/
//Level: Medium


//This question is solved using dp3



//Recursive Solution:

class Solution {
public:

    int recur(int n){

        if(n <= 1){
            return 1;
        }


        int sum = 0;

        for(int i = 1; i <= n; i++){

            sum += (recur(i - 1) * recur(n - i));

        }

        cout << sum << " ";

        return sum;

    }

    int numTrees(int n) {
        
        return recur(n);

    }
};



//Top Down Approach:

class Solution {
public:

    int recur(int n, vector<int> dp){

        if(n <= 1){
            return 1;
        }

        if(dp[n] != 1){
            return dp[n];
        }

        int sum = 0;

        for(int i = 1; i <= n; i++){

            sum += (recur(i - 1, dp) * recur(n - i, dp));

        }


        return dp[n] = sum;

    }

    int numTrees(int n) {

        vector<int> dp(n + 1, 1);
        
        return recur(n, dp);

    }
};




//Bottom Up:

class Solution {
public:

    int recur(int n, vector<int> dp){



        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){

            int sum = 0;
            for(int j = 0; j <= i - 1; j++){
                sum += dp[j] * dp[i - j - 1];
            }
            dp[i] = sum;

        }


        return dp[n];

    }

    int numTrees(int n) {

        vector<int> dp(n + 1);
        
        return recur(n, dp);

    }
};









