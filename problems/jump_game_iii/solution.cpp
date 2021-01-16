class Solution {
public:
    unordered_map<int,bool> M;
    bool canReach(vector<int>& arr, int start) {
        
        if (arr[start]==0) return M[start]=true;
        if (M.count(start)) return M[start];
        M[start] = false;
        if (((start+arr[start]) < arr.size() && canReach(arr,start+arr[start])) ||
           ((start-arr[start]) >=0 && canReach(arr,start-arr[start])))
           M[start] = true;
        return M[start];
    }
};