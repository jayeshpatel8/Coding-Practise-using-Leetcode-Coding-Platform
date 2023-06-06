class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(begin(arr),end(arr));
        for (int i=1 ,d = arr[1]-arr[0]; i<arr.size(); i++)
            if (arr[i-1] +d != arr[i] )   
                return false;
        return true;
    }
};