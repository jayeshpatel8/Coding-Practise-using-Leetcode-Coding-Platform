class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int l=0,N=nums.size(), r=N-1,i=0; i<N; i++){
            if (nums[i] == 0)
                swap(nums[i],nums[l++]);
        }
        for (int l=0,N=nums.size(), r=N-1,i=N-1; i>=0; i--){
            if (nums[i] == 2)
                swap(nums[i],nums[r--]);
        }
        return ;
    }
};
