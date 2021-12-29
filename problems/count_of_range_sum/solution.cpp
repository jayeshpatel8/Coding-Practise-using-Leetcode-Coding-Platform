class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> presum(n+1);
        for (int i=0; i<n; i++) presum[i+1] = presum[i]+nums[i];
        return  mergesort(presum,0,n+1,lower,upper);
    }
    int mergesort(vector<long>& sums, int l, int r, int lo, int up) {
        if (r-l<=1) return 0;
        int m= (r+l)/2;
        
        int cnt = mergesort(sums,l,m,lo,up) + mergesort(sums,m,r,lo,up);
        int j=m,k=m,t=m;
        vector<long> arr(r-l);
       
        for (int i=l,p=0; i<m; i++,p++){
            while(j<r && sums[j]-sums[i] < lo) j++;
            while(k<r && sums[k]-sums[i] <= up) k++;
            while(t<r && sums[t] < sums[i] ) arr[p++]=sums[t++];
            arr[p]=sums[i];
            cnt += k-j;
        }

        for (int i=l,j=0; i<t; i++)
            sums[i] = arr[j++];
        return cnt;
    }
};