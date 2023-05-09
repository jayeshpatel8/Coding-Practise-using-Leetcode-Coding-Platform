class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int M = matrix.size(), N=  matrix[0].size();
        int cnt[2]={N,M-1};
        int dirs[] ={0,1,0,-1,0},s=0,d=0,r=0,c=-1;
        while(cnt[s] > 0){
            for (int t=0; t<cnt[s]; t++){                
                r += dirs[d],c += dirs[d+1];
                ans.push_back(matrix[r][c]);
            }
            cnt[s]--;
            d= (d+1)%4;
            s=(s+1)%2;
        }
        return ans;
    }
};