class Solution {
public:

    int numTimesAllBlue(vector<int>& flips) {
        int ans = 0,max_=0;
        for ( int i =0; i<flips.size(); i++){
            max_ = max(max_ , flips[i]);
            ans+= max_ == i+1;
        }
        return ans;
    }
};