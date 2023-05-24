class Solution {
public:
int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int ans = 0, ma = *max_element(begin(nums), end(nums));
        vector<int> freq(ma+1);

        for (auto n : nums) freq[n]=1;
        for (int i=1; i<=ma; i++)
        {
            int gcd_=0;
            for (int j=i; j <=ma; j+=i){
                if (freq[j] == 0) continue;
                gcd_ = gcd(gcd_,j);
                if (gcd_ == i){ 
                    ans++;
                    break;
                }
            }            
            
        }
        
        return ans;
    }
    int countDifferentSubsequenceGCDs2(vector<int>& nums) {
        int ma = *max_element(begin(nums), end(nums));
        vector<int> factor(ma+1);
        for (auto n : nums){
            for (int i=1; i*i <=n; i++){
                if (n%i != 0) continue;
                int f1= i, f2=n/i;
                factor[f1] = gcd(factor[f1], n);
                factor[f2] = gcd(factor[f2], n);
            }            
        }
        int ans = 0;
        for (auto i=1; i<=ma; i++)
            if (factor[i]==i) ans++;
        return ans;
    }
};