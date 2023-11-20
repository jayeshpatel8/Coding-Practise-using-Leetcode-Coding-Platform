class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size(),ans=0;
        vector<int> t(travel.size()+1),last(3);
        unordered_map<char,int> m ={{'M',0},{'P',1},{'G',2}};
        for (int i=0; i<n; i++){
            for (auto c : garbage[i]) {
                ans++;
                last[m[c]]=i;
            }
        }
        
        for (int i=0; i<n-1; i++){
            t[i+1] =t[i]+travel[i];
        }
        for (auto i : last){
            
                ans += t[i];
        }
        return ans;
    }
};
