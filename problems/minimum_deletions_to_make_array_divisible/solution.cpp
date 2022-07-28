class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsd) {
        sort(begin(nums), end(nums));
        int hcf = reduce(begin(numsd), end(numsd),numsd[0],[](auto a, auto b) {return gcd(a,b);});
        int d=0, N = numsd.size();
        for (int i=0; i<nums.size(); i++){            
            if (hcf % nums[i] == 0) return i;
        }
        return -1;
    }
};