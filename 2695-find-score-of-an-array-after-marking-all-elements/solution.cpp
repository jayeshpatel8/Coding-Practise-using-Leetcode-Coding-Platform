class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
        long long ans = 0;
        for (int i=0; i<nums.size(); i++){
            pq.push({nums[i],i});
        }
        vector<bool> mark(nums.size() + 1 ,false);
        while (!pq.empty()){
            auto [n,i] = pq.top(); pq.pop();
            if (mark[i]) continue;
            mark[i]=true;
            ans +=n;
            if (i > 0) mark[i-1]=true;
            mark[i+1]=true;
        }

        return ans;
    }
};
