class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int c = 0, ans = 0, cur = 0;
        for ( int i= 0; i< gas.size(); i++){
            int c1 =  gas[i] - cost[i];
            cur = max (c1, c1+ cur);
            c += c1;
            if (cur < 0 ) ans = i+1;
        }
        
        if (c<0) return -1;
        return ans ;
    }
};