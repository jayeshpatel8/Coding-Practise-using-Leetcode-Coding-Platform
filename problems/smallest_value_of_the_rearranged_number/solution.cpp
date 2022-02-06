class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(num);
        bool neg =  (s[0] =='-');
        if (neg)
            sort(rbegin(s),rend(s)-1);
        else
            sort(begin(s),end(s));        
         if (!neg && s[0]=='0'){
             for (auto &c : s)
                 if (c != '0'){
                     swap(c,s[0]);break;
                 }
         }
        return stoll(s);
    }
    long long smallestNumber1(long long num) {
    
        bool neg = num<0;
        vector<int> d;
        
        for (long long n=neg ?  num*-1: num; n;  n/=10){
            d.push_back(n%10);
        }
        if (d.size() <2) return num;
        if (neg)
            sort(rbegin(d),rend(d));
        else
            sort(begin(d),end(d));
        if (!neg){
            if (d[0]==0)
                for (int i=0; i<d.size(); i++){
                    if (d[i]) {
                        swap(d[0],d[i]);
                        break;}
                }
            
        }
        long long ans = 0;
        for (auto i : d){
            ans  = ans * 10 + i;
        }
        return neg ? ans * -1 : ans;
    }
};