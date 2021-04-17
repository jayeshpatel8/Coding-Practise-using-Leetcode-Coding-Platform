
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int M=matrix.size(), N=matrix[0].size();
      
        int ans=0;

        for (int i=0; i<N; i++){
            
            vector<int> p_sum(M,0);    
            for (int c=i; c<N; c++)
            {                 
                for (int r=0; r<M; r++){
                    p_sum[r] +=matrix[r][c];                   
                }                
                
                unordered_map<int,int> m;
                m[0]=1;
                int curr = 0;
                for(auto k : p_sum){
                    curr += k ;
                    if (m.count(curr-target)){ans += m[curr-target];}
                    m[curr]++;
                }
            }
        }
 
        return ans;
    }
};
