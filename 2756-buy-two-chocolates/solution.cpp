class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(begin(prices),end(prices));
        int c = prices[0] + prices[1];
        return c > money ? money : money - c;
    }
};
