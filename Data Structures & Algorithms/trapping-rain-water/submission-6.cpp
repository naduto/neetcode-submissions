class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int prefix[n]={0};
        int suffix[n]={0};
        for(int i=0;i<n;i++)
        {
            if(i)
            {
                prefix[i]=max(height[i],prefix[i-1]);
            }
            else
            {
                prefix[i]=height[i];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i!=n-1)
            {
                suffix[i]=max(height[i],suffix[i+1]);
            }
            else
            {
                suffix[i]=height[i];
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=min(prefix[i],suffix[i])-height[i];
        }
        return res;
    }
};