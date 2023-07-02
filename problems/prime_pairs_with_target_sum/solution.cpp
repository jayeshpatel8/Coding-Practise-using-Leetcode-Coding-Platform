class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
       vector<int> prime(n+1);
        for (int i=2; i<=sqrt(n); i++){
            if (prime[i]) continue;
            for (int j=i*i; j<=n; j+=i)
                prime[j]=1;
        }
        vector<vector<int>> ans;

        for (int i=2; i<=(n/2); i++){
            if (prime[i]) continue;
            int j =  n - i;
            if (prime[j]) continue;
            ans.push_back({i,j});
        }
        return ans;
    }
};