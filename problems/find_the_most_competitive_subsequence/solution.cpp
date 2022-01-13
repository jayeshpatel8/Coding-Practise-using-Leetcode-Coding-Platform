class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans(n);
        
        ans[0]=nums[0];
        for (int i=1,j=1; i<n; i++){
            
            while( j> 0 && (ans[j-1] > nums[i]) && (n - i - 1 + j)>=k){                
                j--;
                
            }
            ans[j++]=nums[i];
        }
        vector<int> a(begin(ans),begin(ans)+k);
        
        return a;
    }
};