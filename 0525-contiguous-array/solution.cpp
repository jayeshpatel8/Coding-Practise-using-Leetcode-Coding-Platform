class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans= 0, cnt[2]={};
        int d=0;
        unordered_map<int,int>m;
        m[0]=-1;
        for (int i=0; i<nums.size(); i++){
            cnt[nums[i]]++;
            d = cnt[1]-cnt[0];
            if (m.count(d)) 
                ans = max(ans, i - m[d]);
            else m[d]=i;
        }
        return ans;
    }
};
