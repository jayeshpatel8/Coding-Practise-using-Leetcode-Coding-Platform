class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int ans=1;
        for (int i=1 ,c=  2 ,N= grades.size(); i<N; ){
            i+=c;            
            ans += (i<=N);
            c++;
        }
        return ans;
    }
};