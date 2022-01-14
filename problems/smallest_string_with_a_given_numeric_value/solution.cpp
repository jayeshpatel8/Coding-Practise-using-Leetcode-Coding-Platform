class Solution {
public:
    string getSmallestString(int n, int k) {
        int m = 26 * (n-1);
        string s;
        while (n--){
            int d = k - m;
            if (d <= 0)
                 s+='a', k -= 1;
            else 
                s+='a' + d - 1, k -= d;
            m -= 26;
        }
        return s;
    }
};