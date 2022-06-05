class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        while (nums.size() > 1){
            int  N= nums.size()/2;
            vector<int> arr(N);
            for (int i=0; i<N; i++){
                if (i & 1)
                    arr[i] = max(nums[2 * i], nums[2 * i + 1]);
                else
                    arr[i] = min(nums[2 * i], nums[2 * i + 1]);
            }
            swap(nums,arr);
        }
        return nums[0];
    }
};