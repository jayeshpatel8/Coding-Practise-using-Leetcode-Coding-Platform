class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
             vector<bool> ans;
        for (auto i = 0; i < l.size(); ++i) {
            if (r[i] - l[i] < 2)
                ans.push_back(true);
            else {
                vector<int> n(begin(nums) + l[i], begin(nums) + r[i] + 1);
                int j = 2;
                sort(begin(n), end(n));
                for (; j < n.size(); ++j)
                    if (n[j] - n[j - 1] != n[1] - n[0])
                        break;
                ans.push_back(j == n.size());
            }
        }
        return ans;
    
    }
};