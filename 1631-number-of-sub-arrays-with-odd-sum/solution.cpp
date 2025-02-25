class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd=0,even=0, ans=  0 , mod = 1e9  +7;
        for (auto i : arr){
            if  (i & 1)  {
                 ans =(ans + 1UL+ even) % mod;
                 swap(odd,even);
                 odd++;
            }
            else
                  ans +=odd,even++;
        }
        return ans;
    }
};
