//Question: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/
//Level: Medium


//This question is solved by DP 3!



//Recursive solution:

class Solution {
public:

    pair<int, int> recur(vector<int> arr, int first, int end, int& sum) {
        if (first == end) {
            return {0, arr[first]};
        }

        int ans = INT_MAX;
        int maxLeaf = 0;

        for (int i = first; i < end; i++) {
            pair<int, int> left = recur(arr, first, i, sum);
            pair<int, int> right = recur(arr, i + 1, end, sum);

            ans = min(ans, left.first + right.first + left.second * right.second);
            sum = min(sum, ans);

            maxLeaf = max(maxLeaf, max(left.second, right.second));
        }

        return {ans, maxLeaf};
    }


    int mctFromLeafValues(vector<int>& arr) {
        
        int sum = 0;
        return recur(arr, 0, arr.size() - 1, sum).first;
        

    }
};




//Top Down:

class Solution {
public:

    pair<int, int> recur(vector<int> arr, int first, int end, int& sum, unordered_map<int, pair<int, int>> dp) {
        if (first == end) {
            return {0, arr[first]};
        }

        if(dp.find((first * 10) + end) != dp.end()){
            return dp[(first * 10) + end];
        }

        int ans = INT_MAX;
        int maxLeaf = 0;

        for (int i = first; i < end; i++) {
            pair<int, int> left = recur(arr, first, i, sum, dp);
            pair<int, int> right = recur(arr, i + 1, end, sum, dp);

            ans = min(ans, left.first + right.first + left.second * right.second);
            sum = min(sum, ans);

            maxLeaf = max(maxLeaf, max(left.second, right.second));
        }

        return dp[(first * 10) + end] = {ans, maxLeaf};

    }


    int mctFromLeafValues(vector<int>& arr) {
        
        unordered_map<int, pair<int, int>> dp;
        int sum = 0;
        return recur(arr, 0, arr.size() - 1, sum, dp).first;
        

    }
};





//Bottom Up:





class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> maxLeaf(n, vector<int>(n, 0));

        // Fill in the maxLeaf table where maxLeaf[i][j] is the maximum leaf value in the subarray arr[i...j]
        for (int i = 0; i < n; i++) {
            maxLeaf[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxLeaf[i][j] = max(maxLeaf[i][j - 1], arr[j]);
            }
        }

        // Fill in the DP table
        for (int length = 2; length <= n; length++) {  // length is the length of the subarray
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxLeaf[i][k] * maxLeaf[k + 1][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};










