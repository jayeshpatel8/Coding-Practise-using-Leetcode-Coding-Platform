class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(begin(price),end(price));
        int n = price.size();        
        int l = 0, r = price[n-1] - price[0];
        auto check = [&](int m){
            int k1=k-1;
            for (int i=n-1,j=i; i>=0 && k1; i--)
                if (price[j]-price[i] >= m)
                    k1--,j=i;
            return k1==0 ;
        };
        while (l<r){
            int m = (r+l+1)/2;
           
            if (check(m)){
                l=m;
            }
            else
                r=m-1;
        }
     
        return l;
    }
};