class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs),end(costs));
        int ans = 0;
        for (auto i : costs){
            if (i> coins)break;
            coins -=i;
            ans++;
        }
        return ans;
    }
};