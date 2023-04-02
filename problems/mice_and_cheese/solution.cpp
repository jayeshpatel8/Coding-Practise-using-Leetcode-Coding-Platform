class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<array<int,2>> diff;
        for (int i = 0; i< reward1.size(); i++){
            diff.push_back({reward1[i],reward2[i]});
        }
        sort(begin(diff),end(diff),[&](auto & a, auto &b){
                return a[1]-a[0] < b[1]-b[0];
            });
        int ans = 0;
        for (int i = 0; i<reward1.size(); i++){
            ans += diff[i][!(i<k) ];
        }
        return ans;
    }
};