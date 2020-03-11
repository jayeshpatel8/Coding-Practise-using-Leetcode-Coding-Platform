int fact_t[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
 long fact( long n) { 
   if ((n>=0)&&(n<=10))
      return fact_t[n];
   else
      return n*fact(n-1);
}
string getPermutation_(string& s,  int n, int k,  vector<bool>& used){
   
    if (0 == n)
        return s; 

    int  perDigit = fact(n-1);
    int cur_grp=cur_grp= (k-1)/perDigit;
    k -= cur_grp * perDigit;
   
    int cnt=-1; int i; 
    for (i=0; i<used.size();i++){
        if(!used[i] && (++cnt >= cur_grp)){
            s.push_back('1'+i);
            used[i]=true;            
            getPermutation_(s, n-1, k,  used) ;
            break;
        }             
    }
    
    return s;
}
class Solution {
public:
    string getPermutation(int n, int k) {
     
        string s;        
        s.clear();
        vector<bool> used(n,0);
        return getPermutation_(s, n, k,  used) ;
    }
};