class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() < 1) return {};
        vector<array<int,2>> a;
        for (int i=0; i<arr.size(); i++){
            a.push_back({arr[i],i});
        }
        sort(begin(a),end(a));
        vector<int> ans(arr.size());
        int r=1;
        ans[a[0][1]]=1;
        for (int i=1; i< a.size(); i++){
            if (a[i][0] == a[i-1][0]) 
                ans[a[i][1]]=r;            
            else
                ans[a[i][1]]=++r;            
        }
        return ans;
    }
};