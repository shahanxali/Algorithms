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


