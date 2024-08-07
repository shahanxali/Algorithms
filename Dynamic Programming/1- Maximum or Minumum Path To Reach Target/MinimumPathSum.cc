//Question: https://leetcode.com/problems/minimum-path-sum/description/
//Level: Medium

//THE QUESTION IS SOLVED USING DYNAMIC PROGRAMMING PART 1


//Recursive solution:


class Solution {
public:

    int dp(vector<vector<int>> grid, int x, int y){

        if(x == 0 && y == 0){
            return grid[x][y];
        }
        
        if(x < 0 || y < 0){
            return INT_MAX;
        }


        return min(dp(grid, x - 1, y), dp(grid, x, y - 1)) + grid[x][y];

    }

    int minPathSum(vector<vector<int>>& grid) {
        
        return dp(grid, grid.size() - 1, grid[0].size() - 1);

    }
};




//TOP DOWN:

class Solution {
public:

    int dp(vector<vector<int>> grid, int x, int y, vector<vector<int>>& vec){

        if(x == 0 && y == 0){
            return grid[x][y];
        }
        
        if(x < 0 || y < 0){
            return INT_MAX;
        }

        if(vec[x][y] != 0){
            return vec[x][y];
        }

        return vec[x][y] = min(dp(grid, x - 1, y, vec), dp(grid, x, y - 1, vec)) + grid[x][y];



    }

    int minPathSum(vector<vector<int>>& grid) {

        vector<vector<int>> vec(grid.size(), vector<int>(grid[0].size(), 0));
        
        return dp(grid, grid.size() - 1, grid[0].size() - 1, vec);

    }
};





//BOTTOM UP:


class Solution {
public:

    int dp(vector<vector<int>> grid, int x, int y, vector<vector<int>>& vec){

        vec[0][0] = grid[0][0];

        for(int i = 1; i < grid.size(); i++){
            vec[i][0] = vec[i - 1][0] + grid[i][0];
        }
        for(int i = 1; i < grid[0].size(); i++){
            vec[0][i] = vec[0][i - 1] + grid[0][i];
        }

        for(int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[i].size(); j++){

                vec[i][j] = min(vec[i - 1][j], vec[i][j - 1]) + grid[i][j]; 

            }
        }

        return vec[grid.size() - 1][grid[0].size() - 1];

    }

    int minPathSum(vector<vector<int>>& grid) {

        vector<vector<int>> vec(grid.size(), vector<int>(grid[0].size(), 0));
        
        return dp(grid, grid.size() - 1, grid[0].size() - 1, vec);

    }
};









//SPACE OPTIMIZATION:



class Solution {
public:

    int dp(vector<vector<int>> grid, int x, int y, vector<vector<int>>& vec){

        //Will take firs colums as fixed and then one by one taking 
        //each of the element after that column one by one, next respective to row

        int m = grid.size();
        int n = grid[0].size();

        // Create a 1D vector for dynamic programming
        vector<int> dp(n, 0);

        // Initialize the first element
        dp[0] = grid[0][0];

        // Initialize the first row
        for (int j = 1; j < n; ++j) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        // Compute the rest of the dp array
        for (int i = 1; i < m; ++i) {
            // Update the first element of the current row
            dp[0] += grid[i][0];

            // Update the rest of the elements
            for (int j = 1; j < n; ++j) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }

        return dp[n - 1];
    }


    int minPathSum(vector<vector<int>>& grid) {

        vector<vector<int>> vec(grid.size(), vector<int>(grid[0].size(), 0));
        
        return dp(grid, grid.size() - 1, grid[0].size() - 1, vec);

    }
};
