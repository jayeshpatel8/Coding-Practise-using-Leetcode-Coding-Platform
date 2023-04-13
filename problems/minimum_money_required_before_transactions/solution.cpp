class Solution {
public:
    long long minimumMoney(vector<vector<int>>& tr) {
        long long lost=0 ;
        int last_cashback=0,max_cost=0;
        for (auto & a : tr){
            if (a[0] > a[1]){
                lost += a[0]-a[1] ;
                last_cashback = max(last_cashback, a[1]);
            }
            else{
                max_cost = max(max_cost,a[0]);
            }
        }
        return lost + max(last_cashback, max_cost);
    }
};