class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>>car;
        for(int i=0;i<n;i++)car.push_back({position[i],speed[i]});
        sort(car.rbegin(),car.rend());
        stack<double>st;
        for(int i=0;i<n;i++)
        {
            double time=(target-car[i].first)*1.0/(car[i].second*1.0);
            if(st.empty()||st.top()<time)
            {
                st.push(time);
            }
        }
        return st.size();
    }
};
