class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0 ;
        for (int i=1; i< colors.size(); i++){
            if (colors[i] != colors[i-1]) continue;
            if (neededTime[i] < neededTime[i-1])
                swap(neededTime[i] , neededTime[i-1]);
            ans += neededTime[i-1];                        
        }
        return ans;
    }
    int minCost2(string colors, vector<int>& neededTime) {
        int ans = 0;
        for (int i=1; i< colors.size(); i++){
            if (colors[i] == colors[i-1]){
                int j = i, mtime = neededTime[i-1] ,sum = mtime ;
                while (j < colors.size()  && colors[j] == colors[i])
                {
                    sum += neededTime[j];
                    mtime = max(mtime, neededTime[j++]);
                }
                ans += sum - mtime;
                i=j-1;
            }
        }
        return ans;
    }
};