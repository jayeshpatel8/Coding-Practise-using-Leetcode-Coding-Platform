class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        for (int i=0; i<=10; i++){
            ans[i&1] += (n & (1<<i))!= 0;
        }
        return ans;
    }
};