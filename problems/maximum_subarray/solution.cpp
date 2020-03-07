int divCon(vector<int>& nums,int l, int r,int& lm,int& rm,int &sum){
    
    if (l==r){
        return lm=rm=sum=nums[l];
    }
    {
        int m = l+(r-l)/2;
        int lm1,lm2,rm1,rm2,s1,s2;
        int mxr = divCon( nums,l,m,lm1,rm1,s1);
        int mxl = divCon( nums,m+1,r,lm2,rm2,s2);
        
        lm = max(lm1,s1+lm2);
        rm=max(rm2,s2+rm1);
        sum = s1+s2;


        return max(max(mxr,mxl),rm1+lm2);
    }
    
  
}
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
    
    int lm1,rm1,s1;
return divCon(nums,0,n-1,lm1,rm1,s1);
    }
};