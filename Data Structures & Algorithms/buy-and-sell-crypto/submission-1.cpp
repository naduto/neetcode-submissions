class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int prefix[n];
        prefix[0]=prices[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=min(prefix[i-1],prices[i]);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            res=max(res,prices[i]-prefix[i]);
        }
        return res; 
    }
};
