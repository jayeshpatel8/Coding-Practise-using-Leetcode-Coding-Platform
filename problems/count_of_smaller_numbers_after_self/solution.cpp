class Solution {
public:
     static const int N = 20000+1  , base =  10000 + 1;
    int BIT[N] ={} ;
    void add(int i){
        for (; i<N; i += i & -i){
            BIT[i] +=1;
        }
    }
    int get(int i){
        int ans = 0;
        for (; i>0; i -= i & -i)
            ans += BIT[i];
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int M = nums.size();
        vector<int> ans(M);
      
        
        for (int i=M-1; i>=0; i--){
            ans[i] = get(base + nums[i] - 1) ;
            
            add(base + nums[i]);
        }
        return ans;
    }
};