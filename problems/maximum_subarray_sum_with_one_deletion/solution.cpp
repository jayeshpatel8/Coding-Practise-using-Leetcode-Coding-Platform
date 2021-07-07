class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if (arr.size() == 1) return arr[0];
        
        int n = arr.size(),deleted = 0, non_deleted = arr[0];
        
        for (int i=1; i<n; i++){
            deleted  = max(non_deleted, deleted + arr[i]);
            non_deleted = max(arr[i] + non_deleted, arr[i]);            
            arr[i] = max(non_deleted,deleted);
        }
        
        return *max_element(begin(arr),end(arr));
    }
};