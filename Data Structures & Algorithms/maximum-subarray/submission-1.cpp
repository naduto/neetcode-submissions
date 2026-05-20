class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0,res=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            currsum=max(currsum+nums[i],nums[i]);
            res=max(res,currsum);
        }
        return res;

    }
};