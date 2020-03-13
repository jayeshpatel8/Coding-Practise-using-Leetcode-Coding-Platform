class Solution {
public:
    string addBinary(string a, string b) {
        int al=a.size(),bl=b.size();
        int l = (al>bl?bl:al);
        int c=0;
        string s;
        while (l--){
            int sum = a[--al]+b[--bl]+c;            
            s.push_back(sum%2+'0');
            c=(sum >97);
        }
        while(al)
        {            
            int sum = a[--al]+c;
            s.push_back(sum%2+'0');
            c=(sum>49);
        }            
        while(bl)
        {
            int sum = b[--bl]+c;
            s.push_back(sum%2+'0');
            c=(sum>49);
        }  
        
        if(c) s.push_back('1');
        reverse(s.begin(),s.end());
        return s;
    }
};