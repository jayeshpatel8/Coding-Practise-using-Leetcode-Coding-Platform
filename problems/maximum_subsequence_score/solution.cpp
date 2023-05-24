class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ids(nums1.size());
        iota(begin(ids),end(ids),0);
        sort(begin(ids),end(ids),[&](auto a , auto b){return nums2[a] > nums2[b];});
        priority_queue<int,vector<int>,greater<>> pq;
        long long ans = 0,sum=0;
        for (auto i=0; i<ids.size(); i++){
            auto idx = ids[i];
            sum += nums1[idx];
            if (i>=k-1){
                if (i>=k)
                    sum -=pq.top(),pq.pop();
                ans = max(ans,  sum * nums2[idx]);
            }
            pq.push(nums1[idx]);
        }
        
        return ans;
    }
};