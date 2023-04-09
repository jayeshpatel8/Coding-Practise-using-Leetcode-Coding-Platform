class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int N = nums.size(),ans = 0;
        for (int i=0; i<N; i++){
                ans= max({ans, Isprime(nums[i][i]),Isprime(nums[i][N-i-1])});
        }
        return ans;
    }
    int Isprime(int i){
        if (i==1) return 0;
        for (int j = 2; j<= sqrt(i); j++){
            if (i %j) continue;
            return 0;
        }
        return i;
    }
};