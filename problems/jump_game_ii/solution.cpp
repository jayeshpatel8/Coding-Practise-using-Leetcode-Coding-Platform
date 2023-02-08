class Solution {
public:
    int jump(vector<int>& nums) {
        int N= nums.size()-1, i = 0, j  = 0, jump=0;
        
        while (j < N){
            int k = 0;
            while (i<=j && i<N) 
                k = max(k,i+nums[i++]);
            
            j = k; jump++;
        }
        return jump;
    }
};