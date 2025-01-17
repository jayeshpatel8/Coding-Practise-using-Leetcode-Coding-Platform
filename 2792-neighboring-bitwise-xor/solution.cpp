class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool ret=0 ;
        for (auto i : derived ){
            ret ^= i;
        }
        return ret== 0;
    }
};
