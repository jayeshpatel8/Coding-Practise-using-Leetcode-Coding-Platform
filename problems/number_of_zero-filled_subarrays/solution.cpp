class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;        
        for (int i=0,j=0; i<nums.size();i++){
            if (nums[i])
                j=i+1;
            ans += i-j+1;
        }
        return ans;
    }
    long long zeroFilledSubarray1(vector<int>& nums) {
        long long ans = 0;
        int i=0,j=-1;
        nums.push_back(1);
        for (; i<nums.size();i++){
            if (nums[i]){                
                if (!nums[j+1]){
                    auto n  = i- j -1;
                    ans += ((unsigned long)n * (n+1))/2 ;
                }
                j=i;
            }            
        }
        return ans;
    }
    long long zeroFilledSubarray2(vector<int>& nums) {
        vector<int> cnt(nums.size());
        for (int i=0; i<nums.size();i++){
            if (!nums[i]){
                if (i>0) cnt[i]=cnt[i-1];
                cnt[i]++;
            }
        }
        return accumulate(begin(cnt),end(cnt),0LL);
    }
};