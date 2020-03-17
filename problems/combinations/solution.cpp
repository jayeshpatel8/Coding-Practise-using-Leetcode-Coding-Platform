void combine_(int n,int k,int j, vector<int>& cur, vector<vector<int>>& res){

    if (k == cur.size()) {res.push_back(cur);return;}      
    for (int i=j; i<=n; i++){      
        cur.push_back(i);
        combine_(n,k,i+1, cur,res);
        cur.pop_back();        
    }
}
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {      
        vector<vector<int>> res;
         if (k==0) return vector<vector<int>>(1,vector<int>());
        vector<int> cur;
        for (int i=1; i<=n; i++){
            cur.push_back(i);            
            combine_(n,k,i+1,cur,res);
            cur.pop_back();            
        }
        return res;
    }
};