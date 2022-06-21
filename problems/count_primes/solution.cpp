class Solution {
public:
    int countPrimes(int n) {
        vector<bool> notaPrime(n);
        int ans=0;
        for (int i=2; i<n; i++){
            if (!notaPrime[i]){
                ans++;
                for (int j=2; j*i<n; j++)
                    notaPrime[j*i]=true;
            }
        }
        return ans;
    }
};