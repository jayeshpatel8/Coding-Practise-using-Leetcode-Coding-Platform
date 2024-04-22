class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        int vis[10000]={0};
         
        for (auto i : deadends){
            int n = stoi(i);
            if (n==0) return -1;
            vis[n]=1;
        }
        
        queue<int> q;
        int t = stoi(target); 
        q.push(t);
        int c=-1;
        vis[t]=1;       
        while(!q.empty()){
            int sz = q.size();
            
            c++;
            
            while(sz-- > 0){
                int n = q.front(); q.pop();    
                if (n ==0) return c;    
                for (int i=0,j=10,k=1; i<4; i++,j*=10){
                    int d = n % j/k;
                    int n1 = (d==9) ? n-(9*k): n+1*k, n2 = (d==0)? n+9*k:n-1*k;
                    if (vis[n1] == 0){
                        q.push(n1);
                        vis[n1]=1;                        
                    }
                    if (vis[n2] == 0){
                        q.push(n2);
                        vis[n2]=1;                        
                    }                    
                    k = j;
                }
            }
        }
        return -1;
    }
};
