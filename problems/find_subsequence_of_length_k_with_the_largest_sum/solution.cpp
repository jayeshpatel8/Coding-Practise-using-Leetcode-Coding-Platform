class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>  pq;
        for (int i=0; i< nums.size(); i++){
            pq.push({nums[i],i});
        }
        vector<pair<int,int>> ans;
        while(k)
        {
            ans.push_back(pq.top());pq.pop();
            --k;
        }
        sort(begin(ans), end(ans), [](auto & a, auto &b){ return a.second < b.second;});
        vector<int> res;
        for (auto &[a,b] : ans)
            res.push_back(a);
        return res;
        
    }
};