class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int N = arr.size()-1;
        if (N < 2) return false;
        int i=0;
        
        while (i<N && arr[i] < arr[i+1]) i++;
        if (i==0 || i>=N) return false;
        
        while (i<N && arr[i+1] < arr[i]) i++;
        if (i>=N) return true;
        
        return false;
    }
};