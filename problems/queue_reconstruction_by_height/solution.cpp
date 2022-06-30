class Solution {
public:
    int BIT[2001]={} , N = 0;
    void add(int i,int k){
        for (; i<=N; i += i & (-i)){
            BIT[i]+=k;
        }
    }
    int get(int i){
        int ans = 0;
        for (; i>0; i-= i & (-i)){
            ans += BIT[i];
        }
        return ans;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(begin(p),end(p),[](auto &a, auto &b){ return a[0] < b[0]  || (a[1]  > b[1] && a[0] ==b[0]);});
        N = p.size();
        vector<vector<int>>  ans(N);
        
        for (int i=1; i<=N; i++) add(i,1);
        for (auto & i : p){
            int l=1, r=N;
            while (l<r){
                int mid = (l+r)/2 , sum = get(mid);                
                if (sum < i[1]+1) l=mid+1;
                else r=mid;
            }
            ans[l-1] = i, add(l,-1);            
        }
        return ans;
    }
    vector<vector<int>> reconstructQueue1(vector<vector<int>>& p) {
        sort(begin(p),end(p),[](auto &a, auto &b){ return a[0] > b[0]  || (a[1]  <b[1] && a[0] ==b[0]);});
        vector<vector<int>>  ans;
        
        for (auto & i : p){
            ans.insert(begin(ans) + i[1], i);
        }
        return ans;
    }
};