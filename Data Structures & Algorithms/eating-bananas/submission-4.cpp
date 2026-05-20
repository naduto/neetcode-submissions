class Solution {
public:
    bool ok(int k,int h ,vector<int>& piles)
    {
        long long cntr=0;
        for(int i=0;i<piles.size();i++)
        {
            cntr+=((piles[i]-1)/k+1);
        }
        if(cntr<=h)return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1,right=*max_element(piles.begin(), piles.end());
        while(left<right)
        {
            int mid=(left+right)/2;
            if(ok(mid,h,piles))
            {
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return right;
    }
};
