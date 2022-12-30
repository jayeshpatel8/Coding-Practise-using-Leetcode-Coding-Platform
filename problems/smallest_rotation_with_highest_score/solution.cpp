class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int N = nums.size();
        vector<int> K(N+1);
        // update the +1 point range of each nums[i]
        for (int i=0; i<N; i++){
            if (nums[i] <=  i){
                int ls = 0;
                int le = (i-nums[i]);
                K[ls]++; // left side start
                K[le+1]--;  // left side end
                K[i+1]++; // right side start
            }
            else{
                int rs=i+1; 
                int re = N- (nums[i]-i);
                K[rs]++; // right side start
                K[re+1]--; // right side end
            }            
        }
        int bestidx=0,best=K[0];
        for (int i=1; i<N; i++) {
            K[i] +=K[i-1];
            if (K[i] >best) best=K[i],bestidx= i;
        }
        return bestidx;
    }
};