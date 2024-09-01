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















