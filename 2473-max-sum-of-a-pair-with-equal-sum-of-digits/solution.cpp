class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = -1;
        for (auto  i : nums){
            auto s = getsum(i);
            if (m.count(s)){
                ans = max(m[s] + i, ans);
                if (i > m[s])
                    m[s]=i;
            }
            else
                m[s]=i;
        }
        return ans;
    }
    int getsum(int i){
        int ans = 0;
        while (i>0){
            ans += i%10;
            i/=10;
        }
        return ans;
    }
};
