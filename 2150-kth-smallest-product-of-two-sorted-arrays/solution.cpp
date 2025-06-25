class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long res=-1 , l = -1e10 , r = 1e10;
        while (l<=r){
            long long m = (l + r) / 2;
            if (count(m,nums1,nums2) >= k){
                res=m, r=m-1;
            }
            else
                l=m+1;
        }
        return res;
    }
    long long count(long long mid,vector<int>& nums1, vector<int>& nums2){
        long long cnt = 0;
        
        for (int i=0; i<nums1.size(); i++){
            int v = nums1[i];
            
            if(v ==0 && mid >= 0 ) 
                cnt += nums2.size();
            else if (v > 0 ){
                cnt += left(mid,v,nums2);
            }
            else if (v < 0)
                cnt += right(mid,v,nums2);
        }
        return cnt;
    }
    long long left(long long mid, long long v, vector<int>& nums2){
        int l=0, r= nums2.size()-1, res=-1;
        while(l<=r){
            int m = (l+r)/2;
            if (v * nums2[m] <=mid) {l=m+1,res=m;}
            else r = m - 1;
        }
        return res+1;
    }
    long long right(long long mid, long long v, vector<int>& nums2){
        int l=0, r= nums2.size()-1, res=r+1;
        while(l<=r){
            int m = (l+r)/2;
            if (v * nums2[m] <=mid) r=m-1,res=m;
            else l = m + 1;
        }
        return nums2.size()-res;
    }    
   
};
