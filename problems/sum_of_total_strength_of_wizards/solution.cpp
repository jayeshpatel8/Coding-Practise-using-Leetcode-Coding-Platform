class Solution {
public:
    int totalStrength(vector<int>& st) {
        int N = st.size(), mod =1e9 + 7;
        vector<long long> psum(N+1,0L); // double prefix sum
        vector<long long> ppsum(N+2,0L); // double prefix sum
        partial_sum(begin(st),end(st),begin(psum) + 1,[&](auto v, auto f){return (v + f)%mod;});
        partial_sum(begin(psum),end(psum),begin(ppsum)+1,[&](auto v, auto f){return (v + f)%mod;});

        vector<int> left(N, -1), right(N,N),stack;
        int ans = 0;
        for (int i=0; i<N; i++){
            while(!stack.empty() && st[stack.back()] >= st[i])
                stack.pop_back();
            left[i] = stack.empty() ? -1 : stack.back();
            stack.push_back(i);
        }
        stack.clear();
        for (int i=N-1; i>=0; i--){
            while(!stack.empty() && st[stack.back()] > st[i])
                stack.pop_back();
            right[i] = stack.empty() ? N : stack.back();
            stack.push_back(i);
        }        
        
        for (int i=0; i<N; i++){
            // [ (left + 1) ... i ... (right - 1) ]
            long long         sum = ((ppsum[right[i] +1] - ppsum[i+1]) * (i - left[i]) % mod + mod  - 
               (ppsum[i +1] - ppsum[left[i]+1 ]) * (right[i] - i) % mod + mod) % mod * st[i] % mod;
            ans = (ans + sum) %mod;
        }
        return ans;
    }
    int totalStrength2(vector<int>& st) {
    long long MOD = 1'000'000'007;
    const int N = st.size();
    // sum of first k elements
    vector<long long> prefix(N + 1, 0L);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = (prefix[i] + st[i]) % MOD;
    }
    // sum of first k prefix
    vector<long long> prefix_sum(N + 2, 0L);
    for (int i = 0; i <= N; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + prefix[i]) % MOD;
    }
    
    // first index on the left < current st
    vector<int> left(N, -1);
    // mono increase
    vector<int> stack;
    for (int i = 0; i < N; ++i) {
        while (!stack.empty() && st[stack.back()] >= st[i]) {
            stack.pop_back();
        }
        left[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }
    
    // first index on the right <= current st
    vector<int> right(N, N);
    stack.clear();
    for (int i = N - 1; i >= 0; --i) {
        while (!stack.empty() && st[stack.back()] > st[i]) {
            stack.pop_back();
        }
        right[i] = stack.empty() ? N : stack.back();
        stack.push_back(i);
    }

    long long res = 0 ,sum = 0;
    for (int i = 0; i < N; ++i) {
        sum = ((prefix_sum[right[i] + 1] - prefix_sum[i + 1]) * (i - left[i]) % MOD + MOD  - 
               (prefix_sum[i + 1] - prefix_sum[left[i] + 1]) * (right[i] - i) % MOD + MOD) % MOD * st[i] % MOD;
        
        res =  (res + sum) % MOD;

    }
    return (int) res;
}
};