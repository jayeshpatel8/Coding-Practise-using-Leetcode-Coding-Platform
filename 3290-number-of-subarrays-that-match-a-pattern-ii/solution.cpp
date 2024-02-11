class Solution {
public:
vector<int> z;
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m = pattern.size();
        pattern.push_back('-');
        for (int i=1; i<nums.size(); i++){
            if (nums[i] > nums[i-1])         pattern.push_back(1);
            else if (nums[i] < nums[i-1])         pattern.push_back(-1);
            else         pattern.push_back(0);

        }
 
        int  ans = 0;
        z_alg(pattern);
        for (int i=1; i<z.size(); i++){
            if (z[i] == m) ans++;
        }
        return ans;
    }
    void z_alg(vector<int> &s ){
        int n   = s.size() ;
        z.resize(n);
        for (int i=1, l = 0 , r = 0; i <n ; i++){
            if( i > r){
                l = r= i;
                while (r <n  && s[r]==s[r-l]) r++;
                z[i]=r-l;
                r--;
            }
            else{
                int cur  = i-l;
                if (z[cur] + i <= r) z[i]=z[cur];
                else{
                    l=i;
                    while (r <n  && s[r]==s[r-l]) r++;
                    z[i]=r-l;
                    r--;
                }
            }
        }
    }
};
