class Solution {
public:
    int maximumScore(int a, int b, int c) {
     //a = 2, b = 4, c = 6
      int s1,s2,B;
        if (a<b )     {       
            if ( b<c) s1=a,s2=b,B=c;
            else s1=a,s2=c,B=b;
        }
        else{
            s1=b;
            if (a<c) s2=a,B=c;
            else s2=c,B=a;
        }
        //cout << s1 << s2 << B << endl;
        if (s1+s2 <= B) return s1+s2;
        int diff = (s1+s2) - B;
        int part = diff/2;
        return part + min ( s1 + s2 - part - part , B );
    
    }
};