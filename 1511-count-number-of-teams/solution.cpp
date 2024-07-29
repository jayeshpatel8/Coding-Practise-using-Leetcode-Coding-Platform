class Solution {
public:
    int numTeams(vector<int>& rating) {
       int ans = 0;
        for (int i=1; i<rating.size()-1; i++){
             int less[2] ={}, greater[2]={};
            for (int j = 0 ; j<rating.size(); j++){
                if (rating[i] < rating[j])
                    less[i<j]++;
                if (rating[j] < rating[i])
                    greater[i<j]++;
            }
            ans += less[0] * greater[1] + greater[0] * less[1];
        }
        return ans;
    }
};
