class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> b,col;
        int c = 0;
        vector<int> ans;
        
        for ( auto & q : queries){
            if (b.count(q[0])){
                int t = b[q[0]];
                b[q[0]] = q[1];
                if (--col[t] ==0) col.erase(t),c--;

                if (++col[q[1]]==1)
                    c++;                
            }
            else{
                b[q[0]] = q[1];
                if (++col[q[1]]==1)
                    c++;                
            }
            ans.push_back(c);
        }
        return ans;
    }
};
