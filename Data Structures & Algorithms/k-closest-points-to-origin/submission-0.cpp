class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(auto it:points)
        {
            int dist=(it[0]*it[0])+(it[1]*it[1]);
            pq.push({dist,{it[0],it[1]}});
        }
        vector<vector<int>>ret(k);
        int i=0;
        while(i<k){
            ret[i].push_back(pq.top().second.first);
            ret[i].push_back(pq.top().second.second);
            pq.pop();
            i++;
        }
        return ret;
    }
};
