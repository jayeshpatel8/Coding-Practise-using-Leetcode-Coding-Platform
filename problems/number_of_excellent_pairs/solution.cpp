class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        ;
        vector<int> cnt(31);
        for (auto i : unordered_set<int> (begin(nums),end(nums))) cnt[__builtin_popcount(i)]++;
        long long ans=0;
        for (int i=1; i<=30; i++)
            for (int j=1; j<=30; j++)
                if (i+j >= k)
                    ans += cnt[i] * cnt[j];    
        
        return ans;
    }
    long long countExcellentPairs2(vector<int>& nums, int k) {
        unordered_set<int> ust(begin(nums),end(nums));
        vector<int> st;
        for (auto i : ust) st.push_back(__builtin_popcount(i));
        sort(begin(st),end(st));
        long long ans=0, N = st.size();
        for (int i=0; i<st.size(); i++){
            ans = ans + N - (lower_bound(begin(st),end(st),k-st[i])-begin(st));
        }
        return ans;
    }
};