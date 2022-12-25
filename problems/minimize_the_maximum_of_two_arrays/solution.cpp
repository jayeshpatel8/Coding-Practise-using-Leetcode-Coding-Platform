class Solution {
public:
    int minimizeSet(int d1, int d2, int uc1, int uc2) {
        int l=uc1+uc2, r=INT_MAX;        
        int ans=0;
        using ll =  long long;
        ll lcm = (ll)d1 / __gcd(d1,d2) * d2;

        auto check = [&](int m)->bool{
            if (d1==d2){
                ll c = m - m/(d1);
                return (c >= uc1+uc2);
            }
            else{
                ll c = m - m/d1;
                if ( c < uc1) return false;
               ll  c2 = m - m/d2;
                if ( c2 < uc2) return false;
                ll common = c - m / d2 + m / lcm;
                if (c+c2-common < uc1 + uc2) return false;
                return true;
            }
        };
        while (l<r){
            int m = l + (r-l)/2;
            if (check(m)){                
                r=m;
            }
            else l=m+1;
        }
        return r;
    }
};