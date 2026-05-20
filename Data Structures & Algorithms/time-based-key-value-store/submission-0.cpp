class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        
    }   
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";
        vector<pair<int,string>>arr=store[key];
        int l=0,r=arr.size()-1,mid;
        string res="";
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(arr[mid].first<=timestamp)
            {
                res=arr[mid].second;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return res;
    }
};
