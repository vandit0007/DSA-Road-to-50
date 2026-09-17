class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>&image,int oldcolor,int newcolor)
    {
        int n =image.size();
        int m=image[0].size();
        image[row][col]=newcolor;
        if(row-1>=0 && image[row-1][col]==oldcolor)
        {
            dfs(row-1,col,image,oldcolor,newcolor);
        }
        if(row+1<n && image[row+1][col]==oldcolor)
        {
            dfs(row+1,col,image,oldcolor,newcolor);
        }
        if(col-1>=0 && image[row][col-1]==oldcolor)
        {
            dfs(row,col-1,image,oldcolor,newcolor);
        }
        if(col+1<m && image[row][col+1]==oldcolor)
        {
            dfs(row,col+1,image,oldcolor,newcolor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int oldcolor=image[sr][sc];
        if(oldcolor==color)
        {
            return image;
        }
        dfs(sr,sc,image,oldcolor,color);
        return image;
        
    }
};