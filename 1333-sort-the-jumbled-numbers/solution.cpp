class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<array<int,2>> map;
        vector<int> ans(nums.size());
        for (int i=0; i<nums.size(); i++){
            map.push_back({conv(mapping,nums[i]),i});
        }
        sort(begin(map),end(map));
        int j=0;
        for (auto &i : map){
            ans[j++]=nums[i[1]];
        }
        return ans;
    }
    int conv(vector<int>& mapping, int i){
        int ans=0;
        
        if (i==0) return mapping[0];
        string str = to_string(i);
        
        for (auto &c : str)
            ans = ans * 10 + mapping[c-'0'];
       
        return ans;
    }
};
