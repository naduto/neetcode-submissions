class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int res=0;
        stack<int>st;
        vector<int>left(n,-1);
        vector<int>right(n,-1);
        for(int i=0;i<n;i++)
        {
            left[i]=i;
            while(!st.empty()&&heights[st.top()]>=heights[i])
            {
                left[i]=left[st.top()];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--)
        {
            right[i]=i;
            while(!st.empty()&&heights[st.top()]>=heights[i])
            {
                right[i]=right[st.top()];
                st.pop();
            }

            st.push(i);
        }
        for(int i=0;i<n;i++)
        {
            int area=(right[i]-left[i]+1)*heights[i];
            res=max(res,area);
        }
        return res;
    }
};
