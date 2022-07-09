class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        multiset<int> set ;
        vector<int> dp(size(nums), INT_MIN);
        set.insert(dp[0] = nums[0]);
        int i=1,N = nums.size() ,ans = nums[0];
        for (;i<N; i++){
            if (i > k)
                set.erase(set.find(dp[i-k-1]));
            set.insert( dp[i] = *rbegin(set) + nums[i]);
        }
        
        return dp[N-1];
    }
    
    int maxResult2(vector<int>& nums, int k) {
        priority_queue<array<int,2>> pq ;
        pq.push({nums[0],k});
        int i=1,N = nums.size();
        for (;i<N-1; i++){
            
            while ( pq.top()[1] < i){
                pq.pop();
            }
            int best= pq.top()[0];
            
            pq.push({nums[i] +best, i + k});
            
        }
        while (  pq.top()[1] < i) 
            pq.pop();
       
        return N >1 ? pq.top()[0] + nums[N-1] : pq.top()[0];
    }
};