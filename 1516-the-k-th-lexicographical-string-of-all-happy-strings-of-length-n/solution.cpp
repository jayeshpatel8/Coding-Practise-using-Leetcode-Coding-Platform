class Solution {
public:
string ans;
int N,cnt =0;
    string getHappyString(int n, int k) {
        int cnt=1, m = 1 << (n-1);
        if (3 * m < k) return "";
       
        N=n;
        dfs("",k);
       return  ans;

    }
    void dfs(string a,int& k){
        if (k <= 0 ) return;
        if( a.size()==N) { 

            k--;
            if (k==0)
                ans=a;
            return ;
        }
        for (char j='a'; j<'d'; j++ ){
            if (  a.size() > 0 && a.back() ==  j) continue;
            
            
            dfs(a+j, k);
  
        }
    }
};
