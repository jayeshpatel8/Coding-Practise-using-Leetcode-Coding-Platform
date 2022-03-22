class Solution {
public:
    int countCollisions(string d) {
        int ans=0,prev=d[0],r=prev=='R';
        for (int i=1; i<d.size(); i++){
            if (d[i]=='L'){
                if (prev == 'R'){
                    ans +=2 + r -1; prev='S';r=0;continue;
                }
                else if (prev == 'S'){
                    ans +=1; prev='S';continue;
                }
            }
            else if (d[i]=='S'){
                if (prev == 'R'){
                    ans +=r; prev='S';r=0;continue;
                }
            }
            else
                r++;
                prev = d[i];
        }
              
        return ans;
    }
};