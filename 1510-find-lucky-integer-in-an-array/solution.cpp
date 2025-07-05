class Solution {
public:
    int findLucky(vector<int>& arr) {
        int f[501] = {};
        for (auto i: arr) f[i]++;
        
        for (int i=500; i>0; i--)
            if ( f[i] == i) return i;
        return -1;
    }
};
