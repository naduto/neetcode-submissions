class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};
        int fresh=0;
        queue<pair<int,int>>q;
        int cntr[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)fresh++;
                if(grid[i][j]==2){
                    q.push({i,j});
                    cntr[i][j]=0;
                }
            }
        }
        int res=0;
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int newi=i+x[k];
                int newj=j+y[k];
                if(newi>=0&&newi<n&&newj>=0&&newj<m&&grid[newi][newj]==1)
                {
                    grid[newi][newj]=2;
                    fresh--;
                    q.push({newi,newj});
                    cntr[newi][newj]=1+cntr[i][j];
                    res=max(res,cntr[newi][newj]);
                }
            }
        }
        if(fresh)return -1;
        return res;
    }
};
