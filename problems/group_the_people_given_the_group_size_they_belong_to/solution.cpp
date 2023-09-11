class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& sz) {
        map<int,vector<int>> m;
        for (int i=0; i<sz.size(); i++){
            m[sz[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (auto &[g,i] : m){
            int j=0,len=i.size();
            for (int k=len/g; k>0; --k){
                vector<int> t;
                for (int l=0; j< len &&  l<g; l++,j++)
                    t.push_back(i[j]);
                ans.push_back(t);
            }
        }
        return ans;
    }
};