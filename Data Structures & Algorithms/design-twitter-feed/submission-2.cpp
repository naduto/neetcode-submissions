class Twitter {
public:
    map<int,unordered_set<int>>following;
    map<int,vector<pair<int,int>>>posts;
    int timer;
    Twitter() {
        this->timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        vector<int>ret;
        // cout<<posts[userId].empty()<<endl;
        int cntr=1;
        for(auto it:following[userId])
        {
            for(auto it2:posts[it])
            {
                pq.push(it2);
            }
        }
        for(auto it:posts[userId])pq.push(it);
        while(!pq.empty()&&cntr<11)
        {
            ret.push_back(pq.top().second);
            pq.pop();
            cntr++;
        }
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
