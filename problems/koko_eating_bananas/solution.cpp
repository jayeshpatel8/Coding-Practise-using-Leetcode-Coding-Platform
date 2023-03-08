class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;

        while (l<r){
            int m = (l+r)/2 , total = 0;
            for (auto i : piles)
                total += i/m + ((i%m) != 0);            
            if (total > h) 
                l = m +1;
            else
                r=  m ;
        }
        return l;
    }
};