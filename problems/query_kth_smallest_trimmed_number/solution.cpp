class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& qu) {
        vector<pair<string,int>> arr;
        for (int j=0; j<nums.size(); j++){
            arr.push_back({nums[j],j});
        }
        int N = nums[0].size();
        vector<int> ans;
        for (int i=0; i<qu.size(); i++){
            vector<pair<string,int>> t = arr;
            for (auto &j : t)
                j.first = j.first.substr(N-qu[i][1]);
            sort(begin(t),end(t));
            
            ans.push_back(t[qu[i][0]-1].second);
        }
        return ans;
    }
};