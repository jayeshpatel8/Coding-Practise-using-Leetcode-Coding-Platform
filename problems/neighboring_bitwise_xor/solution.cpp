class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool ret=1 ;
        for (auto i : derived ){
            ret ^= i;
        }
        return ret;
    }
};