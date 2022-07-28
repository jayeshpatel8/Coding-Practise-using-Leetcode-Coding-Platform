class Solution {
public:
    int maximumSum(vector<int>& nums) {
        //unordered_map<int,int> map;
        int map[82]={}; // 10^9 =999999999=  9 * 9 = 81
        int ans = -1;
        for (auto i : nums){
            int sum = 0, j = i;
            while (i > 0){
                sum = sum + i%10;
                i/=10;
            }
            if ( map[sum]){
                int a = map[sum];
                if (ans < a + j)
                    ans= a + j;
                if (a < j)
                    map[sum] = j;
            }
            else
                map[sum] = j;
                
        }

        return ans;
    }
};