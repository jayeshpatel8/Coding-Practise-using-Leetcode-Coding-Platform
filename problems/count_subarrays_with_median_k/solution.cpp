class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        
        int i  = find(begin(nums),end(nums),k)-begin(nums), ans = 1;
        unordered_map<int,int> cnt;
        for (int j=i+1, c=0; j<nums.size(); j++){
            c += nums[j]<k ? -1: 1;
            cnt[c]++;
            ans+= (c ==0 || c==1) ;            
        }
        for (int j=i-1, c=0; j>=0; j--){
            c += nums[j]<k ? -1: 1;            
            ans+= (c ==0 || c==1) ;
            ans+= (cnt[-c] + cnt[-c+1]) ;
        }
        return ans;
        
    }
};