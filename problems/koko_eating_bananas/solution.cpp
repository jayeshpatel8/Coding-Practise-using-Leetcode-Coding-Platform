class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto  l=1, r = *max_element(begin(piles), end(piles));
        while(l<r){
            int m = (l+r)/2 , total=0;
            for (auto i : piles){
                total += i/m + (i%m!=0); 
            }
            if (total <= h)
                r = m ;
            else 
                l = m + 1;
        }
        return r;
    }
};