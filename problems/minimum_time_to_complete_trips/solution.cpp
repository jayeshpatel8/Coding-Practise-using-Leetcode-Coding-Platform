class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(begin(time), end(time));
        long long l = time[0], r = 1e14;
        long long ans = 1e14;
        while (l<=r){
            long long m = (l + r )/ 2;
            long long tt= 0;
            for (auto t : time ){
                tt += m  / t;
            }
            if (tt>=totalTrips){
                r = m -1 ;
                ans = min(ans,m);
            }
            else l = m + 1;
        }
        return ans;
    }
};