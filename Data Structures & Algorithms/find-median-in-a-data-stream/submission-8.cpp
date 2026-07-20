class MedianFinder {
public:
    priority_queue<int,vector<int>>pq;
    int cntr;
    MedianFinder() {
        cntr=0;
    }
    
    void addNum(int num) {
        pq.push(num);
        cntr++;
    }
    
    double findMedian() {
        if(cntr%2==0)
        {
            int k=0;
            vector<int>v;
            while(k<(cntr/2)-1)
            {
                v.push_back(pq.top());
                pq.pop();
                k++;
            }
            int temp1=pq.top();
            pq.pop();
            int temp2=pq.top();
            pq.push(temp1);
            for(auto it :v)pq.push(it);
            double ret=(temp1*1.0+temp2*1.0)/(2.0);
            return ret;
        }
        else
        {
            int k=0;
            vector<int>v;
            while(k<(cntr/2))
            {
                v.push_back(pq.top());
                pq.pop();
                k++;
            }
            int temp1=pq.top();
            for(auto it :v)pq.push(it);
            return temp1;
        }
    }
};
