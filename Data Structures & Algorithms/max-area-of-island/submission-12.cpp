class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    bool vis[55][55];
    int n,m;
    int dfs(int ii,int jj,vector<vector<int>>& grid)
    {
        int sz=1;
        vis[ii][jj]=1;
        for(int i=0;i<4;i++)
        {
            int newi=ii+x[i];
            int newj=jj+y[i];
            // cout<<newj<<endl;
            if(newi>=0&&newi<n&&newj>=0&&newj<m&&grid[newi][newj]&&vis[newi][newj]!=1)
            {
                 sz+=dfs(newi,newj,grid);
            }
        }
        return sz;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        // cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vis[i][j]=0;
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j])
                {
                    // sz=0;
                    // cout<<"2"<<j<<endl;
                    int ret=dfs(i,j,grid);
                    res=max(res,ret);
                }
            }
        }
        return res;
    }
};
