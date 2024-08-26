//Question: https://leetcode.com/problems/knight-probability-in-chessboard/
//Level: Medium

//The question is solved using DP 2


//It is pretty easy if you know a little about DP 2, it basically just keeps on checking if the end position exists on board
//if does then add 1 to answer, think about it, create recursive tree, more accuratel use backtrack though


//Recursive solution:

class Solution {
public:

    int recur(int n, int k, int row, int column, int count, int l){
        
        if (row < 0 || column < 0 || row >= n || column >= n) {
            return 0;
        }

        if(count == k){
            return 1;
        }
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;

        if(row >= 0 && column >= 0 && row < n && column < n){
            a = recur(n, k, row - 2, column - 1, count + 1, l);
            b = recur(n, k, row - 2, column + 1, count + 1, l);
            c = recur(n, k, row + 2, column - 1, count + 1, l);
            d = recur(n, k, row + 2, column + 1, count + 1, l);
            e = recur(n, k, row - 1, column - 2, count + 1, l);
            f = recur(n, k, row - 1, column + 2, count + 1, l);
            g = recur(n, k, row + 1, column - 2, count + 1, l);
            h = recur(n, k, row + 1, column + 2, count + 1, l);

            l = a + b + c + d + e + f + g + h;
        }

        return l;

    }

    double knightProbability(int n, int k, int row, int column) {
        
        return recur(n, k, row, column, 0, 0) / pow(8, k);

    }
};





//Top Down:

class Solution {
public:

    int recur(int n, int k, int row, int column, int count, int l, vector<vector<int>> dp){
        
        if (row < 0 || column < 0 || row >= n || column >= n) {
            return 0;
        }

        if(count == k){
            return 1;
        }

        if(dp[row][column] != -1){
            return dp[row][column];
        }


        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;

        if(row >= 0 && column >= 0 && row < n && column < n){
            a = recur(n, k, row - 2, column - 1, count + 1, l, dp);
            b = recur(n, k, row - 2, column + 1, count + 1, l, dp);
            c = recur(n, k, row + 2, column - 1, count + 1, l, dp);
            d = recur(n, k, row + 2, column + 1, count + 1, l, dp);
            e = recur(n, k, row - 1, column - 2, count + 1, l, dp);
            f = recur(n, k, row - 1, column + 2, count + 1, l, dp);
            g = recur(n, k, row + 1, column - 2, count + 1, l, dp);
            h = recur(n, k, row + 1, column + 2, count + 1, l, dp);

            l = a + b + c + d + e + f + g + h;
        }

        return dp[row][column] = l;

    }

    double knightProbability(int n, int k, int row, int column) {

        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return recur(n, k, row, column, 0, 0, dp) / pow(8, k);

    }
};










//Bottom Up:


class Solution {
public:

    int directions[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    

    double recur(int n, int k, int row, int column, vector<vector<vector<double>>> dp){

        dp[0][row][column] = 1.0;

        for (int step = 1; step <= k; step++) {
            for (int nr = 0; nr < n; nr++) {
                for (int nl = 0; nl < n; nl++) {
                    for (auto& d : directions) {
                        int ni = nr + d[0];
                        int nj = nl + d[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            dp[step][nr][nl] += dp[step - 1][ni][nj];
                        }
                    }
                }
            }
        }

        double count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count += dp[k][i][j];
            }
        }

        return count;

    }

    double knightProbability(int n, int k, int row, int column) {

        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));

        
        return recur(n, k, row, column, dp) / pow(8, k);

    }
};









