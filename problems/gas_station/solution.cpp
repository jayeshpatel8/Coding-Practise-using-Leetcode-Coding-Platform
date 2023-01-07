class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0,cur=0, ans=0 , N = cost.size();
        for (int i=0;  i<N; i++){
            int d = gas[i]-cost[i];
            cur = max(d,cur +d);
            sum += d;
            if (cur < 0) ans = i+1;
        }
        if (sum < 0) return -1;    
        return ans;
    }
};