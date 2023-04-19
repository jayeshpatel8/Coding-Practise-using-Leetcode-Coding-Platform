class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
         int ans = 0, ai[3]={0};
        for (int i=0; i<garbage.size(); i++){
            for (auto c : garbage[i]){
                ans++;
                if (c=='M'){
                    ai[0]=i;
                }
                else if (c=='G')
                    ai[1]=i;
                else
                    ai[2]=i;
            }
        }
        vector<int> psum(travel.size()+1);
        for (auto i=0; i<travel.size(); i++)
            psum[i+1]= psum[i] + travel[i];
        
        for (int i=0; i<3; i++){
            ans += (psum[ai[i]]);
        }
        return ans;
    }
};