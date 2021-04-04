class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size());
        prefixSum[0]=nums[0];
        for (int i=1; i < nums.size(); i++){
            prefixSum[i] =prefixSum[i-1] +  nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return left ?(prefixSum[right] -  prefixSum[left-1]):prefixSum[right];        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */