//Question: https://leetcode.com/problems/unique-paths/
//Level: Medium


//This problem is solved using DP 2

//This is just like previous one, where there is on number, but here its 2d grid



//Recursive Solution:


class Solution {
public:

    int recur(int m, int n){

        if(m == 0 || n == 0){
            return 1;
        }

        int a = recur(m - 1, n) + recur(m, n - 1);

        return a;

    }

    int uniquePaths(int m, int n) {
        
        return recur(m - 1, n - 1);

    }
};




//Top Down:

class Solution {
public:

    int recur(int m, int n, vector<vector<int>>& grid){

        if(m == 0 || n == 0){
            return 1;
        }

        if(grid[m][n] != -1){
            return grid[m][n];
        }

        grid[m][n] = recur(m - 1, n, grid) + recur(m, n - 1, grid);

        return grid[m][n];

    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> grid(m + 1, vector<int>(n + 1, -1));

        for(int i = 0; i < m; i++){
            grid[i][0] = 1;
        }
        for(int i = 0; i < n; i++){
            grid[0][i] = 1;
        }
        
        return recur(m - 1, n - 1, grid);

    }
};




//Bottom Up:


class Solution {
public:

    int recur(int m, int n, vector<vector<int>>& dp){

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];

    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> grid(m + 1, vector<int>(n + 1, -1));

        for(int i = 0; i < m; i++){
            grid[i][0] = 1;
        }
        for(int i = 0; i < n; i++){
            grid[0][i] = 1;
        }
        
        return recur(m, n, grid);

    }
};




