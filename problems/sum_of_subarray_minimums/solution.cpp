class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> stack;
        long ans = 0;
        int mod  = 1e9 + 7;
        for (int i=0, sz = arr.size(); i<=sz; i++){
            while (!stack.empty() && (i==sz || arr[stack.back()] >= arr[i])){
                int mid = stack.back(); stack.pop_back();
                int  l  = stack.empty() ?  -1 : stack.back();
                int r = i;
                long cnt = ((mid- l) * (r-mid) )%mod;
                ans =  (ans  +  (cnt * arr[mid])%mod) %mod;                
            }
            stack.push_back(i);
        }

        return ans % mod;
    }
};