class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int r = lower_bound(begin(arr),end(arr),x)- begin(arr);
        int l = r-1, N =arr.size();
        
        while (k-- > 0){
            if (r >=N || (l>=0 && x-arr[l] <= arr[r]-x))    --l;
            else r++;
        }
        return {begin(arr) + l + 1 , begin(arr)  + r};
    }
};