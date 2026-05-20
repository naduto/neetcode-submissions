class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_gas=0,sum_cost=0;
        for(int i=0;i<gas.size();i++)
        {
            sum_gas+=gas[i];
            sum_cost+=cost[i];
        }
        if(sum_gas<sum_cost)return -1;
        int index=0,i=0,sum=0;
        while(i<gas.size())
        {
            sum+=(gas[i]-cost[i]);
            if(sum<0)
            {
                index=i+1;
                sum=0;
            }
            i++;
        }
        return index;
    }
};
