class Solution {
public:
    int minOperations(vector<int>& A) {
        vector<int> s = {0};
        int res = 0;
        for (int a : A) {
            while (!s.empty() && s.back() > a) {
                s.pop_back();
            }
            if (s.empty() || s.back() < a) {
                res++;
                s.push_back(a);
            }
        }
        return res;
    }
};
