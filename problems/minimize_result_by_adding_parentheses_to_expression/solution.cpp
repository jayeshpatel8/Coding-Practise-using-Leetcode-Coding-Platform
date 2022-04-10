class Solution {
public:
    string minimizeResult(string exp) {
        int n1 = exp.find('+'), n2= exp.size()-n1-1,i1=-1,j1=-1;
        long ans = LONG_MAX;
        for (int i=0; i<n1; i++){
            for (int j=1 ;  j<=n2; j++){
                int n11 = i==0? 1: stoi(exp.substr(0,i));
                int n12 = stoi(exp.substr(i,n1-i));
                int n21 =stoi(exp.substr(n1+1,j));
                int n22 = j==n2? 1: stoi(exp.substr(n1+1+j,n2-j));
                
                if (ans > (long)n11 * (n12 + n21) * n22)
                    i1=i,j1=n1+j, ans = (long)n11 * (n12 + n21) * n22;
            }
        }
        string res;
        for (int i=0; i<exp.size(); i++){
            if (i==i1){
                res +='(';res +=exp[i];
            }
            else if (i ==j1){
                res +=exp[i];res +=')';            
            }
            else
                res +=exp[i];
            
        }

        return res;
    }
};