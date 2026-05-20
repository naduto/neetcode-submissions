class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&temperatures[i]>st.top().first)
            {
                int index=st.top().second;
                st.pop();
                ans[index]=i-index;
            }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};