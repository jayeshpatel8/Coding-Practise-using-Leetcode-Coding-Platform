class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int N = nums.size();
        vector<int> fre(N+1);
        for (auto i : nums) fre[i]++;
        int max_cnt = *max_element(begin(fre),end(fre));
        vector<vector<int>> ans (max_cnt);
        for (int i=1; i<=N; i++){
            for (int j = fre[i]-1; j>=0; j--){
                ans[j].push_back(i);
            }
        }
        return ans;
    }
};