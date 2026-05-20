class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(i!=j&&i!=k&&j!=k)
                    {
                        if(nums[i]+nums[j]+nums[k]==0)
                        {
                            int mini=min({nums[i],nums[j],nums[k]});
                            int maxi=max({nums[i],nums[j],nums[k]});
                            int sum=nums[i]+nums[j]+nums[k];
                            vector<int>v={mini,sum-(mini+maxi),maxi};
                            st.insert(v);
                        }
                    }
                }
            }
        }
        for(auto it:st)
        {
            res.push_back(it);
        }
        return res;
    }
};