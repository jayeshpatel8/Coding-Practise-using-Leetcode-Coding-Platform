class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        int n = diff.size();
        long cur,start = upper, m = INT_MAX , ma = INT_MIN;;
        if (diff[n-1] <  0)
            start  += diff[n-1];
        cur = start;
        m = min(m, cur);
        ma = max(ma, cur);

        for ( int i= n-1; i>=0; i--){
            cur -= diff[i];
            m = min(m, cur);
            ma = max(ma, cur);
        }
        if (ma > upper)
            m -=  ma-upper;
        
        int ans = 0;
        if (m >= lower)
            ans = 1  + m - lower;  
        return ans;
    }
};