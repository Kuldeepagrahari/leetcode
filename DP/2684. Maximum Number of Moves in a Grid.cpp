#include<bits/stdc++.h>
using namespace std;
// GRID Pattern
class Solution {
public:
    int sam(vector<vector<int>> &grid, int row, int col, vector<vector<int>>&dp, int m , int n){

        if ( row == m || col == n){
            return 0;
        }

        if ( dp[row][col] != -1)return dp[row][col];

         int x[] = {-1, 0, 1};
         int m1 = 0;

         for ( int i =  0; i < 3; i++ ){
            int nr = row + x[i];
            int nc = col + 1;
            if ( nr >= 0 && nr < m && nc < n ){
                if ( grid[nr][nc] > grid[row][col])
              m1 = max(m1, 1 + sam(grid, nr, nc, dp, m, n));
            }
         }
         return dp[row][col] = max(dp[row][col], m1);
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        for ( int i = 0 ; i < m; i++ ){
           ans = max ( ans, sam(grid, i, 0, dp , m, n));
        }
        // 1st col ke kisi bhi block se start ho sakta h
        
        return ans ;
    }
};

int main(){

}