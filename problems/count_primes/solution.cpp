class Solution {
public:
    int countPrimes(int n) {
        if (n <2) return 0;
        vector<bool> p(n,true);
        int c=0;
        
        for (int i=2; i*i <=n; i++){
            if (p[i]){
                for (int j=i*i; j<n; j+=i)   p[j]=false;
            }
        }

        for (int i=2; i <n; i++) 
            if (p[i]) c++;
        return c;
       
    }
};