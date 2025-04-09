class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int f[101]={};

        for (auto i : nums){
            f[i]++;
            
        }
        int ans = 0;
        for (auto j =0; j<101; j++){
            int i =f[j];
            if ( i > 0 ){
                if ( j<k) return -1;
                else if (j>k) ans++;
            }
        }
        return ans;
    }
};
