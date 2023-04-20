class Solution {
public:
    int maximumRobots(vector<int>& times, vector<int>& cost, long long budget) {
        deque<int> dq;
        int ans = 0;
        long long  psum=0;
        for (int i=0, j = 0; i<cost.size(); i++){
            psum += cost[i];

            while (!dq.empty() && (dq.back() < times[i])) dq.pop_back();
            dq.push_back(times[i]);
            long long k = i-j +1;
            if (dq.front() + (k) * psum > budget){
                psum -= cost[j];
                if (dq.front()==times[j++]) dq.pop_front();
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
    int maximumRobots2(vector<int>& times, vector<int>& cost, long long budget) {
        multiset<int> st;
        int ans = 0;
        long long  psum=0;
        for (int i=0, j = 0; i<cost.size(); i++){
            psum += cost[i];
            st.insert(times[i]);
            long long k = i-j +1;
            if (*rbegin(st) + (k) * psum > budget){
                psum -= cost[j];
                st.erase(st.find(times[j++]));
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};