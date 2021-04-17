class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
     
        int M = matrix.size(), N = matrix[0].size();;
        
        
        int ans=INT_MIN;
        for (int i = 0; i<N; i++){
            vector<int> prefix_sum(M,0);
            for (int c = i; c<N; c++){                
                int cur_sum=0, max_sum=INT_MIN;

                for (int r = 0; r<M; r++){                    
                    prefix_sum[r] += matrix[r][c];
                    int v = prefix_sum[r];
                    cur_sum = max(cur_sum + v , v);
                    max_sum = max(max_sum, cur_sum);                                       
                }
                    if (max_sum  <= k){
                        ans = max(ans,max_sum);
                        continue;
                    }                
                    set<int> st{0};
                    int ps=0;
                    for (auto sum : prefix_sum ){
                        ps +=sum;
                        int diff = ps - k;
                        auto it  = st.lower_bound(diff);
                        if (it != st.end()) ans = max(ans,(ps-*it));
                        st.insert(ps);
                    }
                if (ans == k) return ans;
            }
        }      
        return ans;
    }
};