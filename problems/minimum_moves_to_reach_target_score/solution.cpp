class Solution {
public:
    int minMoves(int t, int maxDoubles) {
        int ans = 0;
        while (t>1){
            if (t & 1)
                ans++, t--;
            if (maxDoubles)
                t/=2, maxDoubles--, ans++;
            else{
                ans += t-1; break;
            }
                
            
        }
        return ans;
    }
};