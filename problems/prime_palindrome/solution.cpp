class Solution {
public:
    int primePalindrome(int N) {
        
        vector<int> pp{1,2,3,5,7,11,101};
        int i = pp.size()-1;
        if (N <= pp[i--]){
            while(i>0 && N <= pp[i]) i--;
            return pp[i+1];
        }
        int n;
        string s = to_string(N);
        while(1){
            n = nextPal(s);

            if (isPrime(n)) { 

                return n;
            }

        }
        
        return 0;
    }
    bool isPal(int n){
        int p=0,q=n;
        while(n){
             p = p*10 + n%10;
             n/=10;
        }

        return p==q;
    
    }
    bool isPrime(int n){
        if (n%2 ==0 || n%3==0) return false;
        for (int i=5; i*i <=n; i+=6){
            if (n%i == 0) return false;
            if (n%(i+2) == 0) return false;
        }
        return true;
    }
    int nextPal(string & s){
        int n = s.size();
        int m2=n/2,m1=(n-1)/2;
        int r=s[m2]>=s[m1];
        while(m2<n){
            if (s[m1]+r > '9'){
                r=1;
                s[m1] = s[m2] = '0';
            }
            else{
                s[m1]+=r; s[m2]=s[m1];r=0;
            }
            m1--;m2++;
        }
        int num ;
        // 999 1001
        if (r) { 
            num = pow(10,n)+1;
            s = to_string(num);
        }else
            num = stoi(s);            
        
        return num;
    }
};