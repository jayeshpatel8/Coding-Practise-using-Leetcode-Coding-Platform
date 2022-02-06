class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N  = nums.size(), n = N/3;
        vector<long> suf(N+1);
        priority_queue<int,vector<int>,greater<>> pq;
        priority_queue<int> pq1;
        long long sum = 0, ans=LLONG_MAX;
        for (int i=N-1;  i>=n; i--){
            sum +=nums[i];
            pq.push(nums[i]);
            if (pq.size()>n){
                sum-=pq.top();  pq.pop()   ;  
            }
            if (pq.size() == n) suf[i] = sum;
        }
        sum = 0;
        for (int i=0; i<N-n; i++){
            sum += nums[i];
            pq1.push(nums[i]);
            if (pq1.size()>n){                
                sum-=pq1.top();pq1.pop();
            }
           if (pq1.size() ==n){
             ans = min(ans, sum - suf[i+1]);  
           } 
        }
        return ans;
    }    
};