class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>pq;
        for (auto it:stones)pq.push(it);
        while(pq.size()>1)
        {
            int maxi1=pq.top();
            pq.pop();
            int maxi2=pq.top();
            pq.pop();
            if(maxi1-maxi2)pq.push(abs(maxi1-maxi2));
        }
        if(pq.empty())return 0;
        else return pq.top();
    }
};
