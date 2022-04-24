class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rec, vector<vector<int>>& po) {
       vector<int> p[101];
        for ( auto &r  : rec){
            p[r[1]].push_back(r[0]);
        }
       for (auto &i : p )
           sort(begin(i),end(i));
        int N = po.size();
        vector<int> ans(N);

        for ( int i = 0 ; i < N; i++){
            int x = po[i][0], y = po[i][1];
            int sum = 0;
            
            for (int y1=y; y1<=100; y1++){
                auto &pt = p[y1];
                if(pt.empty())continue;
                auto it  = lower_bound(begin(pt), end(pt),x);
                sum += end(pt) - it;
            }
            ans[i]=sum;            
        }
        return ans;
    }
};