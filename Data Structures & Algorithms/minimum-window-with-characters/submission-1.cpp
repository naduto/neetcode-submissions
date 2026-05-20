class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>freq,has;
        for(auto it:t)freq[it]++;
        int res_left=-1,res_right=-1,mini=INT_MAX,have=0;
        int l=0,need=freq.size();
        // if(s.size()<t.size())return "";
        for(int r=0;r<s.size();r++)
        {
            has[s[r]]++;
            if(freq[s[r]]&&has[s[r]]==freq[s[r]])
            {
                have++;
            }
            while(have==need)
            {
                if((r-l+1)<mini)
                {
                    mini=(r-l+1);
                    res_left=l;
                    res_right=r;
                }
                has[s[l]]--;
                if(freq[s[l]]&&has[s[l]]<freq[s[l]])
                {
                    have--;
                }
                l++;
            }
        }
        string res="";
        if(res_left==-1||res_right==-1)return res;
        for(int i=res_left;i<=res_right;i++)
        {
            res+=s[i];
        }
        return res;

    }
};
