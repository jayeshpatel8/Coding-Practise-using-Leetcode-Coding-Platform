class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<string> st;
        string ns = to_string(n);
        sort(begin(ns),end(ns));

        for (int i = 0; i< 32; i++){
            int a = 1 << i;
            string s = to_string(a);
            sort(begin(s),end(s));
            if (s == ns) return true;
        }
        return false;
    }
};
