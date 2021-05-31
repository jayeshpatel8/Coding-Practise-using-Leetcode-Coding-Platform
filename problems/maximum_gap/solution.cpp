class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n  = nums.size();
        if (n < 2) return 0;
        int hi  = 0, lo = INT_MAX;
        for (auto &i : nums)
            hi  = max (hi, i ),  lo  = min (lo, i );
        int bsize = max((int)(hi-lo)/ (n-1), 1);
        
        vector<vector<int>> bucket( (hi-lo)/(bsize ) + 1, vector<int>() );
        
        for (auto &i : nums){
            
            bucket[(int)(i - lo)/bsize].push_back(i);
            
        }
        int prevh, curl,curh=0 ,ans=0;
        int bn=-1;
        for (auto &b : bucket){
            bn++;
            if(b.empty()) continue;
            
            prevh = curh ? curh : b[0],curl = b[0];
            for (auto &i : b)
                curh  = max(curh,  i), curl = min(curl, i);
            
            ans = max(ans, curl - prevh);
        }
        return ans;
    }
};