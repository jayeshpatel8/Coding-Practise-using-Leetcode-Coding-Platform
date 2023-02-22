class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(begin(weights),end(weights)) ,r = (weights.size()-days+1)*l;
        while (l<r){
            auto m = (l+r)/2;
            auto check = [&](){
                int cnt=0 , w=0;
                for (auto i : weights){
                    if (w+i > m) cnt++,w=0;
                    w+=i;
                }
                cnt+= w>0;
                return cnt  <= days;
            };
            if (check())
                r = m;
            else
                l =  m+1;
        }
        return r;
    }
};