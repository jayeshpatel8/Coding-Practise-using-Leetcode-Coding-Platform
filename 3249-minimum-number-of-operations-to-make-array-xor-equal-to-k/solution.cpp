class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
     
     for (auto  i : nums)    k ^= i;
     int ans = 0;
     while(k) k &=k-1, ans++;
     return  ans;

    }
};
