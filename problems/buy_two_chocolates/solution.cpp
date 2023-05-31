class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        nth_element(begin(prices),begin(prices)+2,end(prices));
        int m = prices[0] + prices[1];
        return money - (m > money ? 0 : m);
    }
};