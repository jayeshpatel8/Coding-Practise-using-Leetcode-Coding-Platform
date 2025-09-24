class Solution {
public:
    string fractionToDecimal(int n1, int d1) {
        if (n1==0) return "0";
        if (abs((long long)d1) == 1)return to_string((long long)n1*d1);
        
        string r = (n1<0 ^ d1<0) ? "-": "";
        unsigned long long n=abs((long long)n1), d=abs((long long)d1);
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
};
