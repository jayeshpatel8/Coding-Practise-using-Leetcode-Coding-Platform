class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
       unordered_map<int,int> M;
        for (auto i : tasks){
            M[i]++;
        }
        int ans=0;
        
        for (auto &[i,f] : M){
            int r =0;
            if (f==1) return -1;
            
            if (f%3 == 1 ){
                if (f==2) ans+=1;
                else{
                    int d = f/3;
                 
                        ans += (f - 3*(d-1))/2 + d-1;
                   
                }
            }
            else{
                ans += f/3 + (f%3) /2;
            }        
            
        }
      
        return ans;
    }
};