class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int> id(nums1.size()), qid(queries.size()),ans(queries.size(),-1);
        iota(begin(id),end(id),0);
        sort(begin(id),end(id), [&](auto a, auto b){return nums1[a] > nums1[b];});
        iota(begin(qid),end(qid),0);
        sort(begin(qid),end(qid), [&](auto a, auto b){return queries[a][0] > queries[b][0];});

        map<int,int> map;
        int i=0;
        for (auto q : qid){
            int qx = queries[q][0], qy = queries[q][1];

            while (i<nums1.size() && nums1[id[i]] >= qx){
                int x = nums1[id[i]], y = nums2[id[i]];
                auto it = map.upper_bound(y);
                if (it == end(map) || it->second <= x+y){
                    it = map.insert({y,x+y}).first;
                    while(it != begin(map) && prev(it)->second <= x+y)
                    map.erase(prev(it));
                }
                i++;
            }
            auto it=map.lower_bound(qy); 
            if (it != end(map))
                ans[q] = it->second;
        }
        return ans;
    }
};

/*
Input: 
nums1 = [4,3,1,2], 
nums2 = [2,4,9,5], 
queri = [[4,1],[1,3],[2,5]]
Output: [6,10,7]

n = [0,1,3,2]
q = [[4,1],[2,5],[1,3]]

map = [[[9,10]]
ans = [6,10 ,7]
*/