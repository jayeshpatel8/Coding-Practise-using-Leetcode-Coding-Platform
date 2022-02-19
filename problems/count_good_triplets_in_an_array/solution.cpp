class Solution {
public:
    int N;
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
         N = nums1.size();
        int idx[N+1];
        for (int i=0; i<N; i++)
            idx[nums2[i]]=i;
        vector<int> R(N+1),L(N+1);
        long long ans=0;
        for (int i=0; i<N; i++)
            add(R,i,1);    
        
        
        for (int i=0; i<N; i++){
            int n = idx[nums1[i]];
            add(R,n,-1);
            ans += 1LL * sum(L,n) * (N-i-1-sum(R,n+1) );
           add(L,n,1);
        }
        return ans;
    }
    void add(vector<int>& A, int i, int k){
        for (int idx=i+1; idx<=N; idx += (idx & (-idx)))
            A[idx]+=k;
    }
    int sum(vector<int>& A, int i){
        int s=0;
        for (int idx=i; idx>0; idx -= (idx & (-idx)))
            s += A[idx];
        return s;
    }
};