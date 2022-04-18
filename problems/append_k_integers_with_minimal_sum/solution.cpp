class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        long long ans=0;
        int prev=0;
        for (auto i : nums){
            long long diff = min(i-prev-1,k);
            if (diff>0){
                 ans += ( diff * (prev+1+ prev+diff) )/2;            
                k-=diff;                
                
            }
            prev = i;
            if (k==0)
                break;
        }
        if (k){
            ans += ( k * (prev+1LL+ prev+k) )/2;
        }
        return ans;
    }
};