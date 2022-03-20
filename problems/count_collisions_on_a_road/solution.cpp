class Solution {
public:
    int countCollisions(string d) {
        int ans=0,prev=d[0];
        for (int i=1; i<d.size(); i++){
            if (d[i]=='L'){
                if (prev == 'R'){
                    ans +=2; prev='S';continue;
                }
                else if (prev == 'S'){
                    ans +=1; prev='S';continue;
                }
            }
            else if (d[i]=='S'){
                if (prev == 'R'){
                    ans +=1; prev='S';continue;
                }
            }
                prev = d[i];
        }
        int r=0;
        for (int i=1; i<d.size(); i++){
            if (d[i]==d[i-1]) r++;
            else{
                if (r && d[i-1]=='R'){
                    ans +=r;
                }
                r=0;
            }
        }
      
        return ans;
    }
};