class Solution {
public:
    int bit[100001]={};
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        for (int i = n-1; i>=0; i--){
            int j = nums[i]+10001;
            ans[i] = psum(j-1);
            update(j);
        }
        return ans;
    }
    void update(int n){
        for (int i=n; i<=20001; i += i & -i)
            bit[i]++;
    }
    int psum(int i){
        int sum=0;
        for (; i; i -= i & -i )
            sum += bit[i];
        return sum;
    }
};