class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int e=0,j=0;
        for (auto i : nums){
            if (i == pivot) e++;
            else if (i < pivot) ans[j++]=i;
        }
        while(e > 0 ) ans[j++]=pivot,e--;
    
        for (auto i :  nums){
            if ( i > pivot) ans[j++]=i;            
        }
        return ans;
    }
};
