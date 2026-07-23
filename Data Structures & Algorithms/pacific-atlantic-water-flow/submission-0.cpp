class Solution {
public:
    int x[4]={0,0,1,-1};
    int y[4]={1,-1,0,0};
    int n,m;
    void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<bool>>& ocean)
    {
        ocean[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int newi=i+x[k];
            int newj=j+y[k];
            if(newi>=0&&newi<n&&newj>=0&&newj<m&&!ocean[newi][newj]&&heights[newi][newj]>=heights[i][j])
            {
                dfs(newi,newj,heights,ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>>res;
        vector<vector<bool>>pac(n,vector<bool>(m,false));
        vector<vector<bool>>atl(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            dfs(i,0,heights,pac);
            dfs(i,m-1,heights,atl);
        }
        for(int i=0;i<m;i++)
        {
            dfs(0,i,heights,pac);
            dfs(n-1,i,heights,atl);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pac[i][j]&&atl[i][j])
                {
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
