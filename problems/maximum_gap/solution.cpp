class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // 4,2,0,10,6,
        int n = nums.size();
        if (n<2) return 0;
        
        int minV = *min_element(nums.begin(), nums.end());
        int maxV = *max_element(nums.begin(), nums.end());
        
        if ( maxV - minV < 2 ) return maxV - minV;

        double interval = (double)n / (maxV - minV);
        vector<pair<int,int>> bucket(n+1,{-1,-1});
        
        for (int i=0; i<n; i++){
            int idx = (int)((int)(nums[i] - minV) * interval);
            if (bucket[idx].first==-1)
                bucket[idx]={nums[i] , nums[i] };
            else{
                bucket[idx].first= min ( bucket[idx].first , nums[i]) ;
                bucket[idx].second = max ( bucket[idx].second , nums[i]) ;
            }
        }
        int diff=0, prev= 0;
        for (int i=1; i<=n; i++){
            if (bucket[i].second!= -1){
                diff = max (diff, bucket[i].first- bucket[prev].second);
                prev = i;
            }
        }        
        return diff;
    }
};