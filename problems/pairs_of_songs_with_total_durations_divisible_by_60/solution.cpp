class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> rem(60);
        int ans= 0;
/*
    a%m + b%m = m
    a%m = (m - b%m) %m;
*/        
        for (auto i : time){
            int r = (60 - (i % 60))%60;            
            //if (rem.count(r)){
                ans+=rem[r];
            //}
            rem[i%60]++;
        }
        return ans;        
    }
};
