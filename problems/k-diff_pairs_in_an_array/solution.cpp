class Solution {
public:
    int findPairs(vector<int>& nums, int k){
        sort(begin(nums), end(nums));
        int ans= 0 ;
        for(int l=0, r=1, N = nums.size(); l<N && r<N ; ){
           int d = nums[r]-nums[l];
            if (d==k){
                ans++;r++;
                while (r<N && nums[r]==nums[r-1]) r++;
            }
            else if (d < k )
                r++;                            
            else{
                l++;
                if (l==r) r++;
            }
        }
        return ans;
    }
    int findPairs2(vector<int>& nums, int k) {
        map<int,int> cnt;
        int ans = 0;
        for (auto i : nums) cnt[i]++;
        if (k==0){
            for (auto&[n,v] : cnt) ans += v>1;
            return ans;
        }
        for (auto&[n,v] : cnt)            
            ans +=cnt.count(n-k)>0;
        return ans;
    }
};