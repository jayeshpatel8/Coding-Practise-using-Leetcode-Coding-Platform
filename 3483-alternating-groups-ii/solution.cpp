class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans=0,  N= colors.size();
        for (int i=1,j=1,prev=colors[0]; i< N + k -1; i++){
            if (prev == colors[i%N]) j=1;
            else {
                if (++j >=k) ans++;
            }
            prev = colors[i%N];
        }
        return ans;
    }
};
