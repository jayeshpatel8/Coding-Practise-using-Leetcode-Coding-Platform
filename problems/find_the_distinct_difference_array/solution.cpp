class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int  n = nums.size();
        vector<int> pre(n),suf(n+1);
        int f[51]={};
        for (int i=0,d=0; i<n; i++){
            d += (f[nums[i]]++ ==0);
            pre[i]=d;
        }
        int f2[51]={};
        for (int i=n-1,d=0; i>=0; i--){
            d += f2[nums[i]]++ ==0;
            suf[i]=d;
        }
        vector<int> ans(n);
        for (int i=0;i<n; i++){
            ans[i]=pre[i]-suf[i+1];
        }
        return ans;
    }
};