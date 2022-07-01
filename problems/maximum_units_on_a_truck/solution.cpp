class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes),[](auto &a , auto &b){ return a[1]>b[1];});
        int ans = 0;
         for (auto i : boxTypes){
             ans += ( min(i[0] , truckSize) * i[1]);
             if (truckSize <= i[0]) break;
             truckSize -= i[0];
         }
        return ans;
    }
};