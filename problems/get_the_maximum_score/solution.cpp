class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size(), N2 = nums2.size(), i = 0, j = 0;
        int a=0,b=0 ,mod=  1e9+ 7;
        long n1=0,n2=0, ans= 0;
        while (i<N1 && j<N2){
            a = nums1[i] , b = nums2[j];
            if (a == b){
                ans = (ans + a + max(n1,n2));
                n1=n2=0;i++,j++;
            }
            else if (a < b){
                n1+=a, i++;
            }
            else 
                n2+=b,j++;
        }
        while (i<N1 ) n1+=nums1[i++];
        while (j<N2 ) n2+=nums2[j++];
        ans +=max(n1,n2);
        return ans % mod;
    }
};