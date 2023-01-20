class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int N = nums.size();
        set<vector<int>> ans;
        for (int mask=3; mask <= (1 << N)-1; mask++ ){
            vector<int> seq;
            bool found=true;
            for (int i=0; i<N; i++){
                if (mask & (1<<i)){
                    if (seq.empty() || seq.back() <= nums[i])
                        seq.push_back(nums[i]);
                    else{
                        found=false; break;
                    }
                }
            }
            if (found && seq.size() > 1) ans.insert(seq);
        }
        return vector<vector<int>>(begin(ans),end(ans));
    }
};