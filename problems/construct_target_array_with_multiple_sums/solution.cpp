class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq (target.begin(), target.end());
        
        int n=target.size();
            // 9  3  5 
        long long int sum = 0;
        for (auto i : target)
            sum += i;
        if (1 == n && target[0]!=1 ) return false;
        
        while(1){
            long long int  t = pq.top(); pq.pop();
            
            sum -= t;
            if (sum == 1 || t==1) return true;          
            long long int  c  = t %sum; 
            
            if ( t - sum <= 0|| c==0) return false;
            
            pq.push(c);
            sum +=c;
          
            
        }
        return true;
    }
};