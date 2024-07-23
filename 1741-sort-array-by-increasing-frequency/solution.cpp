class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int f[201];
        for (auto i  : nums) f[i + 100]++;
        sort(begin(nums), end(nums),[&](auto a, auto b){
            return f[a+100] == f[b+100] ? a > b : f[a+100] <= f[b+100];
        });

        return nums;
    }
};
