class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int,int>> pq;
        for (int i=0; i<n; i++){
            int s = m-(upper_bound(mat[i].rbegin(),mat[i].rend(),0)-mat[i].rbegin());
            pq.push_back({s,i}); 
        }
        sort(pq.begin(), pq.end(), [](const pair<int,int>&a, const pair<int,int>&b){return (a.first==b.first?(a.second<b.second):(a.first<b.first));});
        vector<int> res;
        auto it = pq.begin();
        for (int i=0; i<k; i++) {res.push_back(it->second); it++;}
        return res;
    }

};