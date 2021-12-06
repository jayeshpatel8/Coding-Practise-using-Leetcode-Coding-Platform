class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int odd = 0, even = 0;
        
        for (auto i : pos){
            if (i & 1)
                odd++;
            else
                even++;     
        }
        if (even < odd)
            return even;
        return odd;
    }
};

/*

 1 2 3 4 5 6
*/