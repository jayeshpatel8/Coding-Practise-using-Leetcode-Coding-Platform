typedef pair<int,int> PII;
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        //apples = [1,2,3,5,2], days = [3,2,1,4,2]
         //[0,1,0,3,2]
        
        int N = days.size();
        vector<int> dp(N+20001,0);
        int last=N,c=0,start=0;
        for (int d=0; d<last; d++){
            if (d<N){
                int new_start = days[d] + d;
                dp[new_start] +=apples[d];
                if (new_start < start) start = new_start;
                if(new_start > last ) last = new_start;
            }
            while((  start <= d || dp[start]==0 ) && start < last ) start++;
            
            if (dp[start]){
                dp[start]--;
                c++;
            }
        }

        return c;
    }
};