class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int min_=INT_MAX;
        priority_queue<int>pq;
        for (auto & i : nums){
            if (i & 1) 
                i <<=1;
            pq.push(i);
            min_ = min(min_ , i);
        }
        int ans = INT_MAX;
        while (pq.top()%2 == 0){
            int i = pq.top();pq.pop();
            ans = min(ans, i- min_);
            min_ = min(min_ , i/=2);
            pq.push(i);
        }
        if (pq.empty()) return ans;
        return min(ans, pq.top()- min_);
        
    }
};