class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> trees(growTime.size());
        iota(begin(trees), end(trees), 0);
        sort (begin(trees), end(trees), [&](auto & a, auto &b){
            return growTime[a] > growTime[b];
        });
        int plantdays=0, ans = 0;
        for ( auto & i : trees){
            plantdays +=plantTime[i];
            ans = max(ans , plantdays + growTime[i]);
        }
        return ans;
    }
};
