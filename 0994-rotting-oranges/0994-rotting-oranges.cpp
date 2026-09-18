class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
     int n=grid.size();
     int m=grid[0].size();

     queue<pair<pair<int,int>,int>>q;
     vector<vector<int>>vis;
     //initialy taking all rotten oranges into queue
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i,j},0});
            }
        }
     }
     int tm=0;
     while(!q.empty())
     {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        q.pop();

        tm=max(tm,t);
        if(r-1>=0 && grid[r-1][c]==1)
        {
            grid[r-1][c]=2;
            q.push({{r-1,c},t+1});
        }
        if(r+1<n && grid[r+1][c]==1)
        {
            grid[r+1][c]=2;
            q.push({{r+1,c},t+1});
        }
        if(c-1>=0 && grid[r][c-1]==1)
        {
            grid[r][c-1]=2;
            q.push({{r,c-1},t+1});
        }
        if(c+1<m && grid[r][c+1]==1)
        {
            grid[r][c+1]=2;
            q.push({{r,c+1},t+1});
        }
     }
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                return -1;
            }
        }
     }
     return tm;


    }
};