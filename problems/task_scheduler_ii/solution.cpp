class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long cur = 1, ans = 0;
        unordered_map<long long,long long> m;
        //m[tasks[0]]=1;
        for (int i=0; i<tasks.size(); i++){
            auto it = m.find(tasks[i]);
            ans++;
            if (it ==  m.end()){                
                m[tasks[i]]= ans;
            }
            else{
                auto diff = m[tasks[i]] + space + 1;
                if (ans <  diff ){
                    ans = diff;                    
                }
                m[tasks[i]]= ans;
            }
           // cout << i << " " << ans <<endl;
        }
        return ans;
    }
};