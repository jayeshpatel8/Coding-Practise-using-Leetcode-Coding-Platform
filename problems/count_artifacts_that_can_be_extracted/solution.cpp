class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        unordered_map<int,int>m,p;
        for (auto & a : artifacts){
            int p1  = a[0] * n + a[1];            
            for (int r1=a[0]; r1<=a[2]; r1++){
                for (int c1= a[1], c2 = a[3]; c1<=c2; c1++){
                    m[p1]++, p[r1 * n + c1]=p1;
                  
                }
                
            }
        }
        int ans=0;
        for (auto &d : dig){
            int p1 = d[0] * n + d[1];
            auto it  = p.find(p1);
            if (it != p.end() && --m[it->second] == 0)
                ans++;

        }
        return ans;
    }
};