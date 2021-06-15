class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes), [](const vector<int>& a, const vector<int>& b){ return a[1] > b[1];});
        uint64_t ans=0;
        for (auto i : boxTypes){
            
            ans += min(truckSize, i[0])*i[1];
            truckSize -= i[0];
            if (truckSize<=0) break;
        }
        return ans;
    }
};