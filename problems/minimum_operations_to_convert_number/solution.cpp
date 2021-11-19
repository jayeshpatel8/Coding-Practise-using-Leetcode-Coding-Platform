class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
     
        queue<int> q;
        q.push(start);
        int ans =1;
        int map[1001]={};
        while(!q.empty()){
            int sz = q.size();
            while (sz-- > 0){
                int s = q.front(); q.pop();
                for (auto i : nums){
                    {

                        if (i+s == goal || s-i == goal || ((i^s) == goal))
                            return ans;   
                        if (isValid(i+s) && map[i+s] == 0) map[i+s] = 1,q.push(i+s);
                        if (isValid(s-i)&& map[s-i] == 0) map[s-i] = 1,q.push(s-i);
                        if (isValid(s^i) && map[s^i] == 0) map[s^i] = 1,q.push(s^i);                
                    }
                }
            }
            ans++;
        }
        return -1;
    }
    bool isValid(int x){
        return (x>=0 && x<=1000);
    }
};