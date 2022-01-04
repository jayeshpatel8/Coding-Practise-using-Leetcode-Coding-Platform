class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& A) {
        sort(begin(A), end(A));
        uint64_t m = mass;
        for (auto i : A){
            if (m < i) return false;
            m +=i;
        }
        return true;
    }
};