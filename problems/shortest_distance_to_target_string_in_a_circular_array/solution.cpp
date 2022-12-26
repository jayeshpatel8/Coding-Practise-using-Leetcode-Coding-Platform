class Solution {
public:
    int closetTarget(vector<string>& words, string target, int si) {
        int ans= INT_MAX, n  =words.size();;
        if (words[si]==target) return 0;
        for ( int i=0;  i<words.size(); i++){
            if (words[i] == target)
            {
                int dist = abs(i-si);
                ans= min(ans,dist);
                ans= min(ans,n-dist);
                
            }
        }
       
        return ans==INT_MAX ?-1: ans;
    }
};