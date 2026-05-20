class Solution {
public:

    bool dfs(int node,vector<int>& adj, vector<bool>& vis)
    {
        if (node >= adj.size() - 1) return true;
        if(vis[node])return false;
        vis[node]=true;
        for(int i=node;i<=adj[node];i++)
        {
            if(dfs(i,adj,vis))return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>adj(nums.size());
        vector<bool>vis(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            adj[i]=i+nums[i];
        }
        return dfs(0,adj,vis);
    }
};
