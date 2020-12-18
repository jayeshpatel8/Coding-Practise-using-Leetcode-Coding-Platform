class Solution {
public:
    int strongPasswordChecker(string pass) {
        
        int n =  pass.length();
        if (n<3) return 6-n;
        vector<int>  reminder{0,0,0};
        int lo=1,up=1,di=1,replace=0;
        
        int del = max (0, n-20);
        
        for (int i = 0; i<n ;){        
            int c = pass[i];
            if (i>=2 && c==pass[i-2] && c==pass[i-1]){
                int j=i-2;i++;
                while (i<n && c==pass[i]) i++;
                int diff = (i-j);
                if (diff >=3){
                    replace += diff / 3;
                    reminder[diff % 3]++;
                }
            }
            else
             i++;
            if (lo && c >= 'a' && c <= 'z') lo=0;
            else if (up && c >= 'A' && c <= 'Z') up=0;
            else if (di && c >= '0' && c <= '9') di=0;
        }
        int d = del;
        for (int i=0; d > 0 && i < 2; i++ ){
            int m = min ( reminder[i] , d /(i+1)  ) ;            
            replace -= m;
            d=max(d - reminder[i] * (i + 1), 0);
        }
        
        if (d) replace -= d /3;
        
        int ins = max (lo+up+di, 6-n);
        //cout << "del :" << del << " replace: " << replace << " ins: " << ins << endl;
        return del + max(replace,ins);             
    } 
};
