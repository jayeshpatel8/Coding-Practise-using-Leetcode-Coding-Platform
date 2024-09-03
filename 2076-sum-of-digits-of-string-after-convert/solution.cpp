class Solution {
public:
    int getLucky(string s, int k) {
     int ans = 0;
     int m[26]={1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,10,2,3,4,5,6,7,8};
        k--;
        for (auto c : s){
            ans += m[c-'a'];
        }   
        while (k--){
            int n = 0;
            while (ans > 0){
                n += ans % 10;
                ans /=10;
            }
            ans = n;
        }
        return ans;
    }
};
