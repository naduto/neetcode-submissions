class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>count;
        int l=0,res=INT_MIN,second_max=0;
        vector<int>resss;
        for(int r=0;r<nums.size();r++)
        {
            count[nums[r]]++;
            res=max(res,nums[r]);
            if((r-l+1)==k)
            {
                resss.push_back(res);
                count[nums[l]]--;
                if(count[nums[l]]==0)
                {
                    
                    int temp=INT_MIN;
                    for(int j=l+1;j<=r;j++)
                    {
                        temp=max(temp,nums[j]);
                    }
                    res=temp;
                }
                l++;
            }
        }
        return resss;
    }
};