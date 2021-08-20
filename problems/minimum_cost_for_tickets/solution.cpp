class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        queue<pair<int,int>> q7,q30;
        int cost = 0;
        for (auto d : days){
            while(!q7.empty() && d >= q7.front().first + 7  ) q7.pop();
            while(!q30.empty() && q30.front().first + 30 <= d) q30.pop();
            q7.push({ d , cost + costs[1]});
            q30.push({ d ,cost + costs[2]});
            cost = min({
                            cost + costs[0],
                            q7.front().second,
                            q30.front().second,
                       });
        }
        return cost;
    }
    /*
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int maxday =days[days.size()-1] , dp[30]={}, i = 0;
        //O(365), Mem O(30) mem optimized
        for  (int d = days[0]; d <=maxday; d++){
            if (d < days[i]) { dp[(d % 30)] = dp[(d -1)% 30]; continue;}
            i++;

            dp[(d % 30)] = min({ 
                            costs[0]  + dp[(d -1) % 30],
                            costs[1]  + dp[max(0, d-7)%30],
                            costs[2]  + dp[max(0, d-30)%30]
                        });

        }
        return dp[maxday%30];
    }*/
};
/*  O(365), Mem O(365)
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int maxday =days[days.size()-1] , dp[maxday+1], i = 0;
        dp[0]=0;
        for  (int d=days[0]; d <=maxday; d++){
            if (d < days[i]) { dp[d] = dp[d-1]; continue;}
            i++;
            /*
            // 1 day
            dp[d] = min(dp[d], costs[0]  + costs[d-1]);
            // 7 day
            dp[d] = min(dp[d], costs[1]  + (d-7 > 0) ? costs[d-7] : 0);
            // 30 day
            dp[d] = min(dp[d], costs[2]  + (d-30 > 0) ? costs[d-30] : 0);
            
            dp[d] = min({ 
                            costs[0]  + dp[d-1],
                            costs[1]  + ((d-7 > 0) ? dp[d-7] : 0),
                            costs[2]  + (d-30 > 0 ? dp[d-30] : 0)
                        });

        }
        return dp[maxday];
    }
};
*/
