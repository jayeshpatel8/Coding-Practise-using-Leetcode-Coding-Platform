class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
    int cnt[201] = {}, hash[201] = {}, res = 0;
    for (int len=0; len<nums.size(); len++){
        unordered_set<int> st;
        for (int i=0; i+len<nums.size(); i++){
            cnt[i] += nums[i + len] % p == 0;
            if (cnt[i] <= k) {
                hash[i] = ((long long)hash[i] * 257 + nums[i+len]) % (1000000007);
                res += st.insert(hash[i]).second;
            }
        }
    }
    return res;
}
    int countDistinct2(vector<int>& nums, int k, int p) {        
        set<vector<int>> st;
        for (int i=0,n=nums.size(); i<n; i++){
            vector<int> v;
            for (int j=i, cnt = 0; j<n; j++){
                cnt += (nums[j]%p)==0;
                if (cnt>k)break;
                v.push_back(nums[j]);
                st.insert(v);
            }
        }            
        
        return st.size();
    }
};