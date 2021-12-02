class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
    
        vector<int> uf(n,-1);
        for ( auto &req : requests ){
            int u = find(uf, req[0]), v = find(uf, req[1]);
            bool conn = u ==v ;
            if (!conn){
                conn=true;
                for (auto &res : restrictions){
                    int i = find(uf, res[0]), j = find(uf, res[1]);
                    if ((i==u && j==v) || (i==v && j==u))
                    {conn = false; break;}
                }
                if (conn)
                    uf[u]=v;
            }
            ans.push_back(conn);
        }
        return ans;
    }
    int find(vector<int> & uf,int i){
        return (uf[i] < 0) ? i : (uf[i] = find(uf,uf[i]));
    }
};