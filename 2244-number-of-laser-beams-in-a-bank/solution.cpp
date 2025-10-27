class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0, ans=0;
        for ( auto &i : bank){
            int c = 0;
            for (auto j : i){
                c +=  j=='1';
            }
            if (c){
                ans += prev * c;
                prev = c;
            }
        }
        return ans;
    }
};
