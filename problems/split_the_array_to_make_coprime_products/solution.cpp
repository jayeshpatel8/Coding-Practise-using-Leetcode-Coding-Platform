
class Solution {
public:
   vector<int> sieve;
    int N= 1e6+1;;
    vector<int> PrimeFactors (int x) {
        if (sieve.empty()) {
            sieve.resize(N);
            for (int j = 0; j < N; j ++) sieve[j] = j;
            
            for (int j = 2; j*j < N; j ++) {
                if (sieve[j] != j) continue;
                for (int k = j*j; k < N; k += j)
                    sieve[k] = j;
            }
        }
        
        vector<int> result;
        while (x != 1) {
            int div = sieve[x];
            while (x % div == 0) x /= div;
            result.push_back(div);
        }
        return result;
    }
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> last_factor_ind (N, 0);
        for (int i= 0; i<nums.size(); i++){
            for (int f : PrimeFactors(nums[i])) last_factor_ind[f]=i;
        }
        int i=0 ,last=0;
        for (; i<=last  ;i++){
             for (auto f  : PrimeFactors(nums[i])){
                last = max(last,last_factor_ind[f]);                 
             }
        }
        if (i==n)        
         return -1;
        return i-1;
    }
vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; n > 1 && i < 1000; i += 1 + (i % 2))
        if (n % i == 0) {
            res.push_back(i);
            while(n % i == 0)
                n /= i;
        }
    if (n > 1)
        res.push_back(n);
    return res;
}
};