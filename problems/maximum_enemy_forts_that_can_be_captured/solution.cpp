class Solution {
public:
    int captureForts(vector<int>& forts) {
        int c1 = 0, f1=0, ans = 0;
        
        for (auto i : forts){
            if (i==1){f1++;c1=0;}
            else if (i==0 ){
                if (f1)
                    c1++;
                else c1=0;
            }
            else if (i==-1) {
                ans= max(ans, c1);f1=c1=0;
            }
        }
        c1=0,f1=0;
        for (int j=forts.size()-1; j>=0; j--){
            int i =  forts[j];
            if (i==1){f1++;c1=0;}
            else if (i==0 ){
                if (f1)
                    c1++;
                else c1=0;
            }
            else if (i==-1) {
                ans= max(ans, c1);f1=c1=0;
            }
        }
        return ans;
    }
};