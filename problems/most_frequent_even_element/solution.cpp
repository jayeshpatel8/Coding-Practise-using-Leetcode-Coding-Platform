class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int f[100001]={};
        for (auto i : nums)
            if ((i&1) == 0) f[i]++;
        int ans=-1, fre=0;
        for (int i=0; i<100001; i+=2){
            if (f[i] > fre){
                fre=f[i],ans=i;
            }
        }
        return ans;
    }
};