class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
            {
                string temp=tokens[i];
                int res=0;
                bool neg=0;
                for(auto it:temp)
                {
                    if(it=='-')
                    {
                        neg=1;
                        continue;
                    }
                    res*=10;
                    res+=(it-'0');
                }
                if(neg)res*=-1;
                st.push(res);
            }
            else
            {
                if(tokens[i]=="+")
                {
                    int x=st.top();
                    st.pop();
                    x+=st.top();
                    st.pop();
                    st.push(x);
                }
                else if(tokens[i]=="*")
                {
                    int x=st.top();
                    st.pop();
                    x*=st.top();
                    st.pop();
                    st.push(x);
                }
                else if(tokens[i]=="-")
                {
                    int y=st.top();
                    st.pop();
                    int x=st.top();
                    st.pop();
                    st.push(x-y);
                }
                else if(tokens[i]=="/")
                {
                    int y=st.top();
                    st.pop();
                    int x=st.top();
                    st.pop();
                    st.push(x/y);
                }

            }
        }
        if(st.size()==1)return st.top();
        else return -1;
    }
};
