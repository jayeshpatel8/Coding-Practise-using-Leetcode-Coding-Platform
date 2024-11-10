class Solution {
public:
int bits[32]={};
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        

        for (int i=0,j=0,c=0; i<nums.size(); i++){
            c |= nums[i];
            for (int b=0; b<32; b++) if ( nums[i] & (1<<b)) bits[b]++;
            while (c >= k && j<=i) {
                ans = min(ans, i-j+1);
                
                for (int b=0; b<32; b++){
                    if (nums[j] & (1 << b)){
                        bits[b]--;
                        if  (bits[b] == 0) c &= ~(1 << b);
                    }
                }
                j++; 
            }
        }   
        return ans == INT_MAX ? -1 : ans;
    }
};
