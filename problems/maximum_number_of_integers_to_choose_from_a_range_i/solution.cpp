class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;
        for (auto i : banned)st.insert(i);
        int c = 0;
        for (int i=1,s=0; i<=n ; i++){
            if (st.count(i)) continue;
            if ( s +i > maxSum) return c;
            c++; 
            s+=i;
        }
        return c;
    }
};