class Solution { public: vector<int> largestDivisibleSubset(vector<int>& nums) { int N = nums.size(), idx = 0; vector<int> prev(N,-1) , dp(N), ans; sort(begin(nums), end(nums)); for (int i=1; i<N; i++){ for (int j = i-1; j>=0; j--){ if (nums[i] % nums[j] == 0){ if (dp[j] >= dp[i]){ dp[i] = 1 + dp[j]; prev[i] = j; } } } if (dp[idx] < dp[i]) idx = i; } while(prev[idx] != -1){ ans.push_back(nums[idx]), idx = prev[idx]; } ans.push_back(nums[idx]); return ans; } };
