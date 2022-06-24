class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(begin(target),end(target));
        long sum = accumulate(begin(target),end(target),0L);

        while ( 1){
            long n = pq.top();pq.pop();
            sum -=n;
            if (sum == 1 || n ==1 ) return true; 
            
            if ( sum>=n || sum==0 || n%sum == 0) return false;       
            long diff = n%sum;
            pq.push(diff);            
            sum += diff;
            
            
        }

        return true;
    }

};