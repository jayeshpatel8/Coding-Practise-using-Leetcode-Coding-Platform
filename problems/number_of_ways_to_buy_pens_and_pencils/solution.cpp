class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        auto ans = 0LL;
        for (; total>=0; total-=cost1){
            ans += 1 + total/cost2;
        }
        return ans;
    }
   
};