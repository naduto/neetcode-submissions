class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int>freq;
        for(auto it:nums)
        {
            freq[it]++;
            if(freq[it]>=2)
                return true;
        }
        return false;
    }
};