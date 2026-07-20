class Solution {
public:
    int leastInterval(vector<char>& tasks, int      n) {
        int freq[26]={0};
        for(auto it:tasks)
        {
            freq[it-'A']++;
        }
        priority_queue<pair<int,char>,vector<pair<int ,char>>>pq;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)pq.push({freq[i],i+'A'});
        }
        int res=0;
        queue<char>qq;
        while(!pq.empty())
        {
            res++;
            char t=pq.top().second;
            freq[t-'A']--;
            if(freq[t-'A']>0)qq.push(t);
            pq.pop();
            int temp=n;
            while((!pq.empty())&&(temp>0))
            {
                res++;
                cout<<pq.size()<<endl;
                cout<<endl;
                cout<<temp<<endl;
                t=pq.top().second;
                freq[t-'A']--;
                if(freq[t-'A']>0)qq.push(t);
                pq.pop();
                temp--;
            }
            cout<<endl;
            if((!qq.empty())&&temp>0)res+=temp;
            while(!qq.empty())
            {
                char q=qq.front();
                pq.push({freq[q-'A'],q});
                qq.pop();
            }
        }
        return res;
    }
};
