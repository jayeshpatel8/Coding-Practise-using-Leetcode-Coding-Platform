class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N<3) return N==1 ? nums[0] : max(nums[0],nums[1]);
        int p2=0,p1=nums[0];
       for (int i=1;i<N-1; i++){
           int t = p1;
           p1 = max(p1,p2+nums[i]);
           p2=t;
       }
        int ans = p1;
        p2=0,p1=nums[1];
       for (int i=2;i<N; i++){
           int t = p1;
           p1 = max(p1,p2+nums[i]);
           p2=t;
       }
        return max(ans,p1);
    }

};
    //  2  1 1 3 1 3 100
//   2 3  2
//0  4 3 2
//1  3 
//2 0