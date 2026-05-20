class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        int m=s1.size();
        int n=s2.size();
        for(int i=0;i<n-m+1;i++)
        {
            string temp="";
            for(int j=i;j<m+i;j++)
            {
                temp+=s2[j];
            }
            sort(temp.begin(),temp.end());
            if(temp==s1)return true;
        }
        return false;
    }
};
