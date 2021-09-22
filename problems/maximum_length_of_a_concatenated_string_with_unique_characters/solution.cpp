class Solution {
public:
    int m[16]={},N;
    unordered_map<int,int> dp;
    int maxLength(vector<string>& arr) {
        N=arr.size();
        int j = 0;
        for ( int i=0; i < N; i++){
            int k = 0;
            for  (; k<arr[i].size(); k++){
                int mask = 1<<(arr[i][k] - 'a');
                if (m[j] & mask) {
                    m[j] =0; break;
                }
                else
                    m[j] |= mask;
            }
             j += (k == arr[i].size());
        }
        N= j;
        return dfs();
    }
    int dfs (int i=0, int mask=0){
        if (i >= N) return countbits(mask);
        
        if (mask == (1<<26)-1) return 26;
        //int id = (i<<26) | (mask);
        //if (dp.count(id)) return dp[id];
        int ans = dfs(i+1,mask);
        if ((mask & m[i]) == 0 ){
            ans = max(ans, dfs(i+1,mask|m[i]));
        }
        return /*dp[id] =*/ ans;
    }
    int countbits(int num){
        int cnt =0;
        while(num){
            cnt++; num &=num-1;
        }
        return cnt;
    }
};