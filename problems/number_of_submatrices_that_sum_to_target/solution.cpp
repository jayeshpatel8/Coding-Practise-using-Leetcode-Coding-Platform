class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int M =  mat.size() , N = mat[0].size();
        for (int r =0; r<M; r++){
            for (int c=1; c<N; c++)
                mat[r][c] += mat[r][c-1] ;
        }
        int ans = 0;
        for (int c1 =0; c1<N; c1++){
            for (int c2=c1; c2<N; c2++){
                unordered_map<int,int> map;
                map[0]=1;
                int sum = 0;
                for (int r =0; r<M; r++){
                    sum += mat[r][c2] - (c1>0 ? mat[r][c1-1] : 0);
                    auto it  = map.find(sum-target);
                    if (it != map.end())
                        ans += it->second;
                    map[sum]++;
                }
            }
        }
        return ans;
    }
};