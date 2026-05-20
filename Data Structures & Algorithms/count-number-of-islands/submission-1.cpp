class Solution {
public:
    bool visit[105][105]={};
    vector<pair<int,int>>adj[105][105];
    void dfs(int i,int j)
    {
        visit[i][j]=true;
        for(auto it:adj[i][j])
        {
            if(!visit[it.first][it.second])
                dfs(it.first,it.second);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    if(i-1>=0&&grid[i-1][j]=='1'){
                        adj[i][j].push_back({i-1,j});
                    }
                    if (j-1>=0&&grid[i][j-1]=='1')
                    {
                        adj[i][j].push_back({i,j-1});
                    }
                    if (i+1<n&&grid[i+1][j]=='1')
                    {
                        adj[i][j].push_back({i+1,j});
                    }
                    if(j+1<m&&grid[i][j+1]=='1')
                    {
                        adj[i][j].push_back({i,j+1});
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1' && (!visit[i][j]))
                {
                    res++;
                    dfs(i,j);
                }
            }
        }
        return res;
        
    }
};
