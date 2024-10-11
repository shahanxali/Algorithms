//Question: https://leetcode.com/problems/longest-common-subsequence/
//Level: Medium


//This is solved using DP 4




//Recurcive Solution:

class Solution {
public:
    int recur(string& text1, string& text2, int firstindex, int secondindex) {


        // Base case: If either index reaches the end of the string, return 0
        if (firstindex == text1.size() || secondindex == text2.size()) {
            return 0;
        }

        // If characters match, move both indices forward
        if (text1[firstindex] == text2[secondindex]) {
            return 1 + recur(text1, text2, firstindex + 1, secondindex + 1);
        } else {
            // Otherwise, move one of the indices forward and take the maximum result
            return max(recur(text1, text2, firstindex + 1, secondindex), recur(text1, text2, firstindex, secondindex + 1));
        }


    }

    int longestCommonSubsequence(string text1, string text2) {
        // Start the recursion from the beginning of both strings
        return recur(text1, text2, 0, 0);
    }
};





//Top Down:

class Solution {
public:
    int recur(string& text1, string& text2, int firstindex, int secondindex, vector<vector<int>>& dp) {
        // Base case: If either index reaches the end of the string, return 0
        if (firstindex == text1.size() || secondindex == text2.size()) {
            return 0;
        }

        // If already calculated, return the stored value
        if (dp[firstindex][secondindex] != -1) {
            return dp[firstindex][secondindex];
        }

        // If the characters match, move both indices and add 1 to the result
        if (text1[firstindex] == text2[secondindex]) {
            dp[firstindex][secondindex] = 1 + recur(text1, text2, firstindex + 1, secondindex + 1, dp);
        } else {
            // Otherwise, try both possibilities: skip a character from either string
            dp[firstindex][secondindex] = max(recur(text1, text2, firstindex + 1, secondindex, dp), recur(text1, text2, firstindex, secondindex + 1, dp));
        }

        return dp[firstindex][secondindex];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // DP table initialized to -1 for memoization
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));

        // Start the recursion from the beginning of both strings
        return recur(text1, text2, 0, 0, dp);
    }
};



//Bottom UP


class Solution {
public:
    int computeLCS(string& text1, string& text2, vector<vector<int>>& dp) {
        int n = text1.size();
        int m = text2.size();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;  // Characters match
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // Characters don't match
                }
            }
        }

        // Return the length of LCS
        return dp[n][m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // DP table initialized to 0 (size (n+1) x (m+1))
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Compute LCS
        return computeLCS(text1, text2, dp);
    }
};
