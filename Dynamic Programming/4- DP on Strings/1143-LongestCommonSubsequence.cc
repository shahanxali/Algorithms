//Question: https://leetcode.com/problems/longest-common-subsequence/
//Level: Medium


//This is solved using DP 4




//Recurcive Solution:


class Solution {
public:

    void recur(string& text1, string& text2, int firstindex, int secondindex, int count, int& ans){

        ans = max(ans, count);
        if(firstindex == text1.size() && secondindex == text2.size()){
            return;
        }


        for(int i = firstindex; i < text1.size(); i++){

            for(int j = secondindex; j < text2.size(); j++){

                if(text1[i] == text2[j]){

                    recur(text1, text2, i + 1, j + 1, count + 1, ans);

                }

            }

        }


        return;

    }

    int longestCommonSubsequence(string text1, string text2) {

        int ans = 0;
        recur(text1, text2, 0, 0, 0, ans);

        return ans;

    }
};






//Top Down:


class Solution {
public:

    void recur(string& text1, string& text2, int firstindex, int secondindex, int count, int& ans, vector<vector<int>> dp){

        ans = max(ans, count);

        if(dp[firstindex][secondindex] != -1){
            return;
        }

        if(firstindex == text1.size() && secondindex == text2.size()){
            return;
        }


        for(int i = firstindex; i < text1.size(); i++){

            for(int j = secondindex; j < text2.size(); j++){

                if(text1[i] == text2[j]){

                    dp[i][j] = ans = max(ans, count + 1);

                    recur(text1, text2, i + 1, j + 1, count + 1, ans, dp);

                }

            }

        }


        return;

    }

    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> dp(text1.size() + 1, (vector<int>(text2.size() + 1, -1)));

        int ans = 0;
        recur(text1, text2, 0, 0, 0, ans, dp);

        return ans;

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
