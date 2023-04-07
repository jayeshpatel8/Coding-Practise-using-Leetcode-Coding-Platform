class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> idx(nums1.size());
        iota(begin(idx), end(idx), 0);
        sort(rbegin(idx), rend(idx), [&](int a, int b){
            return nums2[a] == nums2[b] ? nums1[a]>nums2[b]:  nums2[a] < nums2[b];
        });
        long  sum = 0, ans = 0;
        priority_queue<int,vector<int>, greater<int>> q;

        for (int i=0; i<nums1.size(); i++){
            sum += nums1[idx[i]];
            if (i >= k-1){                                
                if (i>=k){
                    sum -=q.top();q.pop();                
                }
                ans = max(ans, nums2[idx[i]]* sum);
                
            }
            q.push(nums1[idx[i]]);
        }

        return ans;
    }
};