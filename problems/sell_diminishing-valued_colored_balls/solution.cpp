class Solution {
public:
    int maxProfit(vector<int>& inv, int o) {
        sort(rbegin(inv),rend(inv));
        int ans = 0, mod  = 1e9 + 7;       
        
        for (int i=0,color=1; o>0 && i<inv.size(); i++,color++){
            long cur = inv[i],  next = i < inv.size()-1 ? inv[i+1]: 0;
            long round = min<int>( o / color, cur-next);
            o -= round * color;
            ans = (ans + ( cur * (cur +1) - (cur-round) * (cur - round +1) ) / 2 * color ) % mod; 
            if (cur - next > round){
                ans = (ans + o * (cur - round)) % mod; 
                break;
            }
        }
        return ans;
    }

};