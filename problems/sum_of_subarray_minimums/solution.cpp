class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n),r(n,n) ,st;
        int ans = 0 , mod = 1e9 + 7;
        for (int i=0; i<=n; i++){
            while (!st.empty() && (i==n || arr[st.back()] >= arr[i])){
                int j = st.back();st.pop_back();
                int k = st.empty() ? -1: st.back();
                ans = (ans  + ((long)arr[j] * (i-j) * (j-k))%mod) % mod;    
            }
            st.push_back(i);
        }

        return ans;
    }

    int sumSubarrayMins2(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n),r(n,n) ,st;
        for (int i=0; i<n; i++){
            while (!st.empty() && arr[st.back()] >= arr[i])
                st.pop_back();
            l[i] = st.empty() ? i+1 : i - st.back();
            st.push_back(i);
        }
        st.clear();
        int ans = 0 , mod = 1e9 + 7; 
        for (int i=n-1; i>=0; i--){
            while (!st.empty() && arr[st.back()] > arr[i])
                st.pop_back();
            r[i] = st.empty() ? n-i :  st.back() - i;
            st.push_back(i);
            ans = (ans  + ((long)arr[i] * l[i] * r[i])%mod) % mod;
        }
        return ans;
    }
};