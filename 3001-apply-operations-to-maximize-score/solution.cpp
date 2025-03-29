class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pscore(n),next(n,n),prev(n,-1);

        for (int i=0; i<n; i++){
            int a = nums[i];
            for (int j=2; j<= sqrt(a); j++){
                if (a%j == 0){
                    pscore[i]++;
                    while(a%j == 0) a/=j;
                }
            }
            if (a>=2) pscore[i]++;
        }
        stack<int> st;
        for (int i=0; i<n; i++){
            while(!st.empty() && pscore[st.top()] < pscore[i]){
                next[st.top()] = i;
                st.pop();
            }
            if (!st.empty())
                prev[i]=st.top();
            st.push(i);
        }
        vector<long long > subarray(n);
        for (int i=0; i<n; i++){
            subarray[i] = (long long)(next[i]-i )* (i-prev[i]);
        }

        priority_queue<pair<int,int>> pq;
        for (int i=0; i<n; i++) pq.push({nums[i], i});

        long long ans=1;
        while (k > 0){
            auto [a,i] = pq.top(); pq.pop();
            long long cnt = min<long long> (k,subarray[i]);
            ans = (ans * power(a,cnt)) %MOD;
            k -= cnt;
        }
        return ans;
    }
    long long power(long long base, long long exponent) {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0) {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }    
};
