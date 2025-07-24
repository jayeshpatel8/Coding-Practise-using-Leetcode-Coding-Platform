class Solution {
public:
    int xor1[1001]={} , N , E;
    int enter[1001]={}, exit[1001]={}, time=1;
    int ans = INT_MAX;
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
         N = nums.size() ; E  = edges.size();
         vector<vector<int>> G(N);
        for (auto &e : edges)
            G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
        dfs(G, nums, 0,-1);
       int a[3];
        for (int i=1; i<N; i++)
        {
            for (int j=i+1; j<N; j++){
                if (enter[i] <= enter[j] && exit[j] <= exit[i]){                             
                    a[0] = xor1[j]; 
                    a[1] = xor1[i] ^ a[0];
                    a[2] = xor1[0] ^ xor1[i];                        
                }
                else if (enter[j] <= enter[i] && exit[i] <= exit[j]){                             
                    a[0] = xor1[i]; 
                    a[1] = xor1[j] ^ a[0];
                     a[2] = xor1[0] ^ xor1[j];                        
                }                
                else{                       
                    a[0] = xor1[j]; 
                    a[1] = xor1[i];
                    a[2] =xor1[0] ^ xor1[j]^ xor1[i];
                }
                sort(a,a+3);
                ans=min(ans,a[2]-a[0]);
            }
        }

        return ans;
    }

        int dfs(vector<vector<int>> &G , vector<int>& nums, int i, int p){

            int x=nums[i];
            enter[i] = time++;
            for (auto j : G[i]){
                if (j!= p)
                    x ^= dfs(G,nums,j,i);
            }
          
            exit[i]=time;
            return xor1[i] = x;
        }
    
};
