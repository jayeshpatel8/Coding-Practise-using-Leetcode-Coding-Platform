class Solution {
public:
    int M ,P,st;
    int minCostSetTime2(int startAt, int moveCost, int pushCost, int ts) {        
        M = moveCost, P = pushCost, st=startAt;
        int ans = INT_MAX;
        for (int m=0;m<100; m++){
            for(int s=0; s<100; s++){
                if (m*60 + s != ts) continue;
                vector<int> v = {m/10, m%10, s/10,s%10};
                for(auto &i : v) if (i==0) i=-1; else break;
                int cur = startAt ,total=0;    
                for(auto i : v){
                    if (i<0) continue;
                    if (cur != i)
                        cur= i, total += M;
                    total += P;
                }
                ans= min(ans,total);
            }
        }
       
        return ans;
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int ts) {        
        M = moveCost, P = pushCost, st=startAt;
        return min(cost(ts/60,ts%60), cost(ts/60 - 1, ts%60 + 60));
    }
    int cost (int m, int se){        
        if (min(m,se)<0 || max(m,se)>99) return INT_MAX;
        string s = to_string(m*100+se);
        
        int tc=0 , p = st+'0';
        for (auto c : s){
            if (p!=c){
                tc += M;
                p = c;
            }            
            tc += P;            
        }
        return tc;
    }  
};