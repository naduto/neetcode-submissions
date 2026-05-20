class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        map<char,int>appearence;
        // appearence[s[i]]=i;
        int res=0;
        while(j<n)
        {
            
            if(appearence.find(s[j])!=appearence.end())
            {
                if(appearence[s[j]]>=i)
                {
                    i=appearence[s[j]]+1;
                }
            }
            appearence[s[j]]=j;
            res=max(res,j-i+1);
            j++;            

        }
        return res;

    }
};