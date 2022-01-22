class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort (begin (cost), end(cost));
        int  n  = cost.size() , c =0;
        for (int i=n-1; i>=0; i--){
            c += cost[i--];
            if (i >= 0)
                c += cost[i--];
        }
        return c;
    }
};