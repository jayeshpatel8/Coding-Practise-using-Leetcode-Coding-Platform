class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto check = [](int a, int b){
                int ba = __builtin_popcount(a) , bb = __builtin_popcount(b);
                return ba==bb ? a<b : ba<bb;
            };
        sort(begin(arr),end(arr),[&](auto a, auto b){return (a==0||b==0 )? a<b : (check(a,b) );});
        return arr;
    }
};