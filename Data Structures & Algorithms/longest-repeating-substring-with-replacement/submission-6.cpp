class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[27]={0};
        int n=s.size();
        int l=0,maxfreq=0,res=0;
        for(int r=0;r<n;r++)
        {
            freq[s[r]-'A']++;
            maxfreq=max(maxfreq,freq[s[r]-'A']);
            while((r-l+1)-maxfreq>k){
                freq[s[l]-'A']--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};
