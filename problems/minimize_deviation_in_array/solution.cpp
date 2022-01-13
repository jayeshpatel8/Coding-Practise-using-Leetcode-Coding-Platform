class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int min_=INT_MAX;
        priority_queue<int> pq;
        for (auto i: nums){
            int n = i%2? (i*2) : i;
            pq.push(n);
            min_ = min(min_,n);
        }
        int ans=INT_MAX;
        while(pq.top()%2 == 0){
            ans=min(pq.top() - min_,ans);
            min_ = min(min_,pq.top()/2);
            pq.push(pq.top()/2);pq.pop();
        }
        return min(ans, pq.top() - min_);;
    }
};