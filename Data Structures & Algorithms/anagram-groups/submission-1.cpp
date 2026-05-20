class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, map<char, int>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            if (mp.find(s) != mp.end()) continue;
            for (int j = 0; j < s.size(); j++) {
                mp[s][s[j]]++;
            }
        }
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i] == "55") continue;
            vector<string> v;
            v.push_back(strs[i]);
            for (int j = i + 1; j < strs.size(); j++) {
                if (strs[j] == "55") continue;
                bool flag = true;
                if (strs[i].size() != strs[j].size()) flag = false;
                else {
                    for (auto it : mp[strs[i]]) {
                        int count=it.second;
                        char ch=it.first;
                        if (count != mp[strs[j]][ch]) {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) {
                    v.push_back(strs[j]);
                    strs[j] = "55";
                }
            }
            res.push_back(v);
        }
        return res;
    }
};