class Solution {
public:
    int maxBottlesDrunk(int nb, int ne) {
        int ans = 0;
        while (nb > 0){
            if (nb >= ne) {
                ans += ne;
                nb -=ne;
                nb++;
                ne++;
            }
            else{
                ans+=nb; nb=0;
            }
        }
        return ans;
    }
};
