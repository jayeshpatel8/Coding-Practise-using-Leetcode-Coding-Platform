class Solution {
public:
using ll =  long long  ;
    string nearestPalindromic(string num) {
        ll n = stoll(num);
        ll prev = prevPal(n);
        ll next = nextPal(n);

        if (n-prev <= next - n) return to_string(prev);
        return to_string(next);

    }
    ll pal(ll num){
        string s = to_string(num);
        int n = s.length();
        ll l = (n-1)/2, r=n/2;
        while(l>=0) s[r++]=s[l--];
        return stoll(s);
    }
    ll prevPal(ll n){
        ll l=0, r=  n, ans = INT_MIN;
        while (l <= r){
            ll m = (r-l)/2 + l;
            ll p = pal(m);    
            if (p < n){
                ans = p, l=m+1;
            }
            else r=m-1;

        }
        return ans;
    }
    ll nextPal(ll n){
        ll l=n, r=  1e18, ans = INT_MAX;
        while (l <= r){
            ll m = (r-l)/2 + l;
            ll p = pal(m);    
            if (p > n){
                ans = p, r=m-1;
            }
            else l=m+1;

        }
        return ans;
    }
};

// 9293  9229 9999 8888
