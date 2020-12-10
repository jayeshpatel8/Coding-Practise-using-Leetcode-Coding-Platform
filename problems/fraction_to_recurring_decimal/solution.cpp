class Solution {
public:
#if 1    
    string fractionToDecimal(int n, int d) {
        if (n==0) return "0";
        if (abs(d) == 1)return to_string((long)n*d);
        
        string r = (n<0 ^ d<0) ? "-": "";
        n=abs(n); d=abs(d);
        r += to_string( n/d);
        if (n>=d && n%d == 0 ) return r;
        
        unordered_map<int,int> map;
        long int rem = n % d;
            
        r += ".";
        
        while( rem !=0 && map.find(rem) == map.end()){
           
            map[rem]=r.length();
            rem  *= 10;
            long int res_part = rem/d;                       
            rem %= d;
            r +=  to_string(res_part);
        }
        if (map.count(rem)>0){
            r.insert(map[rem], "("); r += ")";
        }
        return r;
    }
#else
string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0)
            return "";
        if(numerator == 0)
            return "0";
        int nt = abs(numerator), dt = abs(denominator);
        string ans = "";
        if((long long)numerator * (long long)denominator < 0)
            ans.insert(0, "-");
        long long res = nt % dt, s = nt / dt;

        map<int, int> m;
        if(res == 0) {
            ans += std::to_string(s);
            return ans;
        }
        else
            ans += std::to_string(s) + "."; 
        int i = ans.length();
        while(res != 0) {
            s = (res * 10) / dt;
            if(m.count(res) == 0)
                m[res] = i++;
            else {
                ans.insert(m[res], "(");
                ans += ")";
                break;
            }
            ans += std::to_string(s);
            res = (res * 10) % dt;
            cout << ans << endl;
        }

        return ans;
    }    
#endif
};