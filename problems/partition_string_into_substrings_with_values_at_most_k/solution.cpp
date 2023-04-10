class Solution {
public:
    int minimumPartition(string s, int k) {
        unsigned long sum  = 0,  ans = 1;
        for (auto c : s){
            sum = sum * 10 + c-'0';
            if (sum > k){
                ans++;
                sum = c - '0';
            }
            if (sum > k)return -1;
        }
        return ans;
    }
};