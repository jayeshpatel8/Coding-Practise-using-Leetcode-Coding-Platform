class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=1, N= arr.size() , r= N-1;
        while (l<r){
            int m= (l+r)/2;
            if (arr[m] > arr[m+1])
                r=m;
            if (arr[m] < arr[m+1])
                l=m+1;
        }
        return l;
    }
};