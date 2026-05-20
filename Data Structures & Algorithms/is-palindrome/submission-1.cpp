class Solution {
public:
    bool isPalindrome(string s) {
        
        string t="";
        for(auto &it:s)
        {
            it=tolower(it);
            if((it>='a'&&it<'z')||(it>='0'&&it<='9'))t+=it;
        }
        int i=0,j=t.size()-1;
        while(i<j)
        {
            if(t[i]==t[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};