class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int N = nums1.size();
        vector<int> D(1e5 + 1);
        for (int i=0;i<N; i++)
            D[abs(nums1[i] -nums2[i])]++;

        long long ans = 0, k = k1+k2, kk1=k;  

        
        for (int i=1e5; i>0; i--){
            if (D[i] ==0 ) continue;
            k = min<long long>(D[i],kk1);
            D[i] -=k;
            D[i-1] +=k;
            kk1-=k;
            if (D[i])
                ans += ((long long)i*i) * D[i];
        }
        
        return ans;
    }
};