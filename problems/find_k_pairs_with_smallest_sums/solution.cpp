class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using ar = array<int,3>;
        priority_queue<ar,vector<ar>, greater<>> pq;
        //for (int i=0; i<nums1.size(); i++)
            pq.push({nums1[0]+nums2[0],0,0});
        vector<vector<int>> ans;
        while (k-- > 0 && !pq.empty()){
            auto  [_,i,j] = pq.top();
            ans.push_back({nums1[i],nums2[j]});
            pq.pop();
            if (i==0 && j + 1 < nums2.size())
                pq.push({nums1[i]+nums2[j+1],i,j+1});            
            if (i + 1 < nums1.size())
                pq.push({nums1[i+1]+nums2[j],i+1,j});            
        }
        return ans;
    }
};