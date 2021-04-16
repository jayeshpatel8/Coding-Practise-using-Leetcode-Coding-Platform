class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& nums)
    {
        sort(nums.begin(), nums.end(), [](vector<int> &v1, vector<int> &v2){ 
            //int x1 = v1[0],x2=v2[0], y1=v1[1], y2=v2[1];
            return v1[0]==v2[0] ? v1[1]>v2[1] : v1[0]<v2[0] ; });
        
        vector<int> ans;
        for (auto i : nums){
            int y = i[1];
            auto it = lower_bound(ans.begin(),ans.end(), y);
            if (it==ans.end()) ans.push_back(y);
            else
                *it=y;
        }
        return ans.size();
    }
    
};