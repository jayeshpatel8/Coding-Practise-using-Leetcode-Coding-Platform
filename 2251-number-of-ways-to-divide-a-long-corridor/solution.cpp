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
};
