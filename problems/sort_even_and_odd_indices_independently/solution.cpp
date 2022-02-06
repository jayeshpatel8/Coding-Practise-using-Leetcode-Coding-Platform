class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int f[2][101]={};
        for (int i=0; i<nums.size(); i++)
            f[i&1][nums[i]]++;
        for (int i=0,j=0; i<101; i++){
            while(f[0][i]--)
                nums[j]=i,j+=2;
        }
        for (int i=100,j=1; i>=0; i--){
            while(f[1][i]--)
                nums[j]=i, j+=2;
        }
        return nums;
    }
};