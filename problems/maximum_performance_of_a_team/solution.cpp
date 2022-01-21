class Solution {
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) {
        vector<array<int,2>> v(n);
        priority_queue<int,vector<int>,greater<int>> p1;        
        long sum = 0 ,ans=0;
        int mod = 1e9 +7;
        for (int i=0; i<n; i++){
            v[i] = { ef[i] ,sp[i]};
        }      
        sort(rbegin(v),rend(v));
        for ( int i=0; i<n; i++){                        
            int e = v[i][0], s = v[i][1];
            p1.push(s);
            sum+=s;
             if( p1.size()>k){
                 sum -=p1.top();
                p1.pop();
            }
            ans= max(ans , sum * e);
        }

        
        return ans % mod;
    }
};