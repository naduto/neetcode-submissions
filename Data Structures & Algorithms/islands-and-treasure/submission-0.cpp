class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)q.push({i,j});
            }
        }

        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for (int k=0;k<4;k++)
            {
                int newi=i+x[k];
                int newj=j+y[k];
                if(newi>=0&&newi<n&&newj>=0&&newj<m&&grid[newi][newj]==2147483647)
                {
                    grid[newi][newj]=1+grid[i][j];
                    q.push({newi,newj});
                }
            }
        }
    }
};
