class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>>strss;
        vector<vector<string>>res;  
        for(int i=0;i<strs.size();i++)
        {
            strss.push_back({strs[i],strs[i]});
        }
        for(int i=0;i<strs.size();i++)
        {
            sort(strss[i].first.begin(),strss[i].first.end());
        }
        sort(strss.begin(),strss.end());
        for(int i=0;i<strs.size();i++)
        {
            vector<string>v;
            if(strss[i].first=="55")continue;
            v.push_back(strss[i].second);
            for(int j=i+1;j<strs.size();j++)
            {
                if(strss[i].first==strss[j].first)
                {
                    v.push_back(strss[j].second);
                    strss[j].first="55";
                }
            }
            res.push_back(v);
        }
        return res;
    }
};