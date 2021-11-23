class Solution {
public:
    int uf[100001];
    int ans= 1;
    int largestComponentSize(vector<int>& nums) {
        int m  = *max_element(begin(nums), end(nums));
        
        memset(uf,-1,sizeof(uf));
        
        for( auto i : nums){
            int N = sqrt(i);
            for (int j=2; j<=N; j++){
                if (i % j == 0 ){
                    union_(i,j); 
                    union_(i,i/j);
                }
            }
        }
        unordered_map<int,int> map;
        for (auto i : nums)
            ans= max(ans, ++map[find(i)]);
        return ans;
    }
    int find(int i){
        if (uf[i] == -1)
            return i;
        return uf[i] = find(uf[i]);
    }
    void union_(int i, int j){
        int pi = find(i) , pj = find(j);
        if (pi != pj){
            uf[pi] = pj;
        }
    }
};