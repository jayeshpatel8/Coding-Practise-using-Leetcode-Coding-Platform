class Solution {
public:
    int minimumArrayLength(vector<int>& A) {
        int v = *min_element(A.begin(), A.end());
        for (int x : A)
            if (x % v > 0)
                return 1;
        int cnt = count(A.begin(), A.end(), v);
        return (cnt + 1) / 2;
    }
};
