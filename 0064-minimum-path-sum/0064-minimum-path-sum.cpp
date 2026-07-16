class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //if(grid[0][0]==1 || grid[n-1][m-1]==1)   return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[0][0];
                    continue;
                }
                int up=INT_MAX;
                int down=INT_MAX;
                if(i>0){
                    up=dp[i-1][j]+grid[i][j];
                }
                if(j>0){
                    down=dp[i][j-1]+grid[i][j];
                }
                dp[i][j]=min(up,down);
            }
        }
        return dp[m-1][n-1];
    }
};