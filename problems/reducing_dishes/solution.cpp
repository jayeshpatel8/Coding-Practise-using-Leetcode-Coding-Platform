class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(rbegin(sat),rend(sat));
        int ans = 0;
        for (int i=0 , psum = 0 ; i<sat.size(); i++){
            psum += sat[i];
            if (psum < 0) 
                return ans;
            else
                ans += psum;
            
        }
        return ans;
    }
    int maxSatisfaction2(vector<int>& sat) {
        sort(rbegin(sat),rend(sat));
        vector<int> psum(sat.size()+1);
        for (int i=0; i<sat.size(); i++){
            psum[i+1] = psum[i] + sat[i];
        }
        int ans = 0;
        for (int i=0; i<sat.size(); i++){
            int coe = ans + psum[i+1];
            if (coe < ans) return ans;
            ans = coe;
        }
        return ans;
    }
};