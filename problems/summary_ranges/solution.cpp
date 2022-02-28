class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {        
        int N = nums.size(), prev = 0;
        if (N==0) return {};
        vector<string> ans;
        ans.push_back(to_string(nums[0]));
        for (int i=1;i<N; i++){
            if (nums[i-1]+1 == nums[i]) continue;
            string s = to_string(nums[i-1]);
            if (ans.back() != s){
                ans.back() = ans.back() + "->" + s;
            }
            ans.push_back(to_string(nums[i]));
            prev= i;
        }
        if (prev != N-1){
            ans.back() = ans.back() + "->" + to_string(nums[N-1]);
        }
        return ans;
    }
};