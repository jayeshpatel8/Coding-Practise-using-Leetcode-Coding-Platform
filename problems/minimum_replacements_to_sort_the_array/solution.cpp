class Solution { public: long long minimumReplacement(vector<int>& nums) { long long ans = 0; int N = nums.size(); for (int i=N-2; i>=0; i--){ if (nums[i] <= nums[i+1]) continue; auto cur = nums[i]; int next = nums[i+1]; long parts = cur / next + (cur % next != 0); ans += parts - 1; if (cur % next == 0) nums[i] = next; else nums[i] = cur / parts; 
// select the smallest of all sub part of cur
 } return ans; } };