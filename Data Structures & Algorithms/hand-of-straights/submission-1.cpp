class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        sort(hand.begin(),hand.end());
        int n=hand.size();
        for(int i=0;i<n;i++)mp[hand[i]]++;
        for(int i=0;i<n;i++)
        {
            int j=hand[i]+groupSize-1;
            if(!mp[hand[i]])continue;
            for(int k=hand[i];k<=j;k++)
            {
                if(!mp[k])return false;
                mp[k]--;
            }
        }
        return true;
    }
};
