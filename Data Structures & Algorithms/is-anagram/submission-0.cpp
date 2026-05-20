class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>freq;
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            freq[t[i]]--;
            if(freq[t[i]]<0)
            {
                return false;
            }
        }
        for(auto it:freq)
        {
            if(it.second>0)
            {
                return false;
            }
        }
        return true;
    }
};
