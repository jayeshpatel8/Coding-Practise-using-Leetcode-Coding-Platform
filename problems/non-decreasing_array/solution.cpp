class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i=1, cnt= 0 ,N =nums.size();
        for ( ;  i<N; i++){
            if (nums[i-1] <= nums[i]) continue;
            cnt++;
            if (i==N-1) break;
            if (nums[i-1] <= nums[i+1]){
                nums[i] = nums[i+1];
            }
            else{
                if (i-2>=0 && nums[i-2] > nums[i]) 
                    return false;
                nums[i-1] = nums[i];
            }
        }
        return cnt <= 1;
    }
};