class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l  = left.empty() ? 0 : *max_element(begin(left), end(left));
        int r  = right.empty() ? n : *min_element(begin(right), end(right));
        return max(l,n-r);
    }
};