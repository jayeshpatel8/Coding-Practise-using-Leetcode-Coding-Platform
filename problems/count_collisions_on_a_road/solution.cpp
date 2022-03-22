class Solution {
public:
    int countCollisions(string d) {
        int ans=0,r=d[0]=='R';
        for (int i=1; i<d.size(); i++){
            if (d[i]=='L'){
                if (d[i-1] != 'L'){
                    ans +=r + 1; d[i]='S';r=0;continue;
                }
            }
            else if (d[i]=='S'){
                if (d[i-1] == 'R'){
                    ans +=r; d[i]='S';r=0;continue;
                }
            }
            else
                r++;
        }
              
        return ans;
    }
};