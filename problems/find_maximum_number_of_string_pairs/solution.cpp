class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
     int ans= 0;
        for (auto  i=0 ; i< words.size(); i++){
            if (words[i][0]==-1) continue;
            for (int j=0; j<words.size(); j++){
                if (words[j][0]==-1 || i==j) continue;
                if (words[i][0]== words[j][1] && words[i][1]==words[j][0]){
                    ans++;
                    words[i][0]=words[j][0]=-1;
                    break;
                }
            }
        }   
        return ans;
    }
};