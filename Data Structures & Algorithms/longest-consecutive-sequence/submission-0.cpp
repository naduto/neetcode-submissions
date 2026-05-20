class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it :nums)
        {
            st.insert(it);
        }
        int res=0;
        for(auto it : st)
        {
            if(st.find(it-1)==st.end())
            {
                int cntr=1;
                while(st.find(it+cntr)!=st.end())
                {
                    cntr++;
                }
                res=max(cntr,res);
            }
        }
        return res;

    }
};