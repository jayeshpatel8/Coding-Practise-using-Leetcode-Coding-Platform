class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int spare=0,last_spare=INT_MAX, idx;    
        for (int i=0; i<n ; i++)
        {
            spare += gas[i] - cost[i];
            if (spare < last_spare){
                last_spare = spare;
                idx = i;
            }
        }
        return spare<0 ?-1: (idx+1)%n;
    }
};
/// -1 +1 +2
 