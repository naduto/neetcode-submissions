class KthLargest {
public:
    priority_queue<int,vector<int>>pq;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for(auto it:nums)
        {
            pq.push(it);
        }
    }
    
    int add(int val) {
        int cntr=kth;
        vector<int>temp;
        int ret;
        pq.push(val);
        while(cntr--)
        {
            ret=pq.top();
            pq.pop();
            temp.push_back(ret);
        }
        for(auto it:temp)pq.push(it);
        return ret;
    }
};
