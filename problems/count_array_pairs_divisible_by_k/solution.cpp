class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int>gcd;
        
        long long ans=0;
        
        for(auto i : nums)
            gcd[__gcd(i,k)]++;
        
        for(auto &[a,c1]: gcd){
            for(auto &[b, c2]:  gcd){
                if (a<=b && (a*(long)b)%k == 0){
                    ans += (a==b) ? (c1 * (long)(c1-1)/2) : (c1 *(long)c2);       
                }
            }
        }
        return ans;
    }      

  
};