class Solution {
public:
    string getSmallestString(int n, int k) {        
        string ans(n,'a');
        k-=n--;
        while (k > 0 ){
            int excess = min(25,k);
            ans[n--] += excess;
            k -= excess;
        }
        return ans;
    }
};