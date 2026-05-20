class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res(2);
        vector<pair<int,int>>numss;
        for(int i=0;i<nums.size();i++)
        {
            numss.push_back({nums[i],i});
        }
        sort(numss.begin(),numss.end());
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            int ress=numss[i].first+numss[j].first;
            if(ress==target)
            {
                res[0]=min(numss[i].second,numss[j].second);
                res[1]=max(numss[i].second,numss[j].second);
                return res;
            }
            else if(ress<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return res;
    }
};
