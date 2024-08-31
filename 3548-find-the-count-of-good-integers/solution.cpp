class Solution {
public:
    string p;
    using ll = long long;
    ll ans= 0;
    long long countGoodIntegers(int n, int k) {
        p = string(n,'0');
        genpal(0,n-1,k,n);
        return ans;
    }
    unordered_set<string> vis;
    void genpal(int l, int r, int k, int n){
        if (l >r ){
            ll  num = stoll(p);
            if (num % k ==0 ){
                auto s = p;
                sort(begin(s),end(s));
                if (vis.count(s) == 0){
                    vis.insert(s);
                    ans += calc(num, n);
                }
            }
            return ;
        }
        for (int i= (l==0) ? '1' : '0' ; i<='9'; i++){
            p[l] = p[r] = i;
            genpal(l+1,r-1,k,n);
        }
    }
    ll calc(ll num, int n){
         map<int,int>m;
          while(num){
                    m[num%10]++;
                    num /= 10;
            }
        return Total_Permutations(m,n) -  PermutationsStartWithZero(m,n);

    }
    ll Total_Permutations(map<int, int> &freq, int n) {
        ll totalPermutations = fact(n);

        for (auto i : freq) {
            totalPermutations /= fact(i.second);
        }
        return totalPermutations;
    }
    ll PermutationsStartWithZero(map<int, int> &freq, int n) {
        if ( !freq.count(0) ) return 0;
        freq[0]--;
        ll totalPermutations = fact(n-1);

        for (auto i : freq) {
            totalPermutations /= fact(i.second);
        }
        return totalPermutations;
    }
     ll fact(int n){
        ll ans = 1;
        for(int i=2 ; i<=n ; i++) ans *= i;
        return ans;
    }
};
