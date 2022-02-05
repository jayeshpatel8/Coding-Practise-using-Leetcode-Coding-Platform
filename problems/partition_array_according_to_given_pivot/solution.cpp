class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int N = nums.size();
        vector<int> ans(N);
        int j=0, k=N,i;
        for ( i=0;i<N; i++){
            if (nums[i]<pivot)
                ans[j++]=nums[i];
        }
        for ( i=N-1,k=N;i>=0; i--){
            if (nums[i] > pivot)
                ans[--k]=nums[i];
        }
        
        for ( i=- j + k; i>0; i--)
            ans[j++]=pivot;
        return ans;
        
    }
};