class Solution {
public:
    int candy(vector<int>& ratings) {
       
        int N = ratings.size() ,ans = 0;
        vector<int> cnt(N,1);
        for (int i=1; i<N; i++)
            if (ratings[i-1] < ratings[i])
                cnt[i] = cnt[i-1] + 1;
        ans = cnt[N-1];
        for (int i=N-2; i>=0; i--){
            if (ratings[i+1] < ratings[i])
                cnt[i] = max(cnt[i+1] + 1, cnt[i]);
            ans +=cnt[i];
        }
        
        
        return ans;
    }
    int candy2(vector<int>& ratings) {
        set<array<int,2>> set;
        int N = ratings.size();
        for (int i=0; i<N; i++)
            set.insert({ratings[i] , i});
        vector<int> cnt(N);
        
        for (auto & i : set){
            int j = i[1] , can=0;
            if (j>0 && ratings[j-1] < ratings[j])
                can = cnt[j-1];
            if (j<N-1 && ratings[j+1] < ratings[j])
                can = max(can,cnt[j+1]);
            cnt[j] = can +1;
        }
        return accumulate(begin(cnt),  end(cnt),0);
    }
};