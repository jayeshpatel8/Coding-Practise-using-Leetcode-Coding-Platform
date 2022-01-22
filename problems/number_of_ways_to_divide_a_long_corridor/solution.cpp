class Solution {
public:
    int numberOfWays(string co) {
        int ans = 1, mod =  1e9 + 7,seat = 0;
        long plant = 0;
        for (auto c : co){
            if (c == 'S'){
                if (seat % 2){
                    ans =( ans * (plant + 1)) % mod;
                    plant = 0;
                }
                seat++;
            }
            else if (seat % 2 == 0 && seat !=  0){
                plant++;
            }
        }
        return seat == 0 || seat %2 ? 0 : ans;
    }
    int numberOfWays2(string co) {
        int ans = 1, mod =  1e9 + 7;
        int cnt = 0, total = 0, n = co.size(), d , last;
        for (last = n-1 ; last >=0; last--){
            cnt += co[last]=='S';
            if (cnt == 2) break;
        }
        total +=cnt;
        cnt = 0;
        for (int i = 0, j ; i<last; i++){
            cnt += co[i]=='S';
            if (cnt ==2 && i+1 < last) {
                 d = 1, j = i+1;
                for (; j < last; j++){
                    if (co[j]=='S') break;
                     d++;
                }
                ans  =  (ans  * (long)d) %mod;
                i =j -1;
                total +=cnt;
                cnt  = 0;
            }
        }
        
        total +=cnt;
        
        return (total <  2 || total & 1) ? 0 : ans;
    }
};