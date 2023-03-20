class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {

     for (int i=0; n && i<f.size(); i++)   {
         if (!f[i]){
             if (i!=0 && f[i-1]) continue;
             if (i+1 != f.size() && f[i+1]) continue;
             f[i]=1;n--;
         }
     }
     return n==0;
    }
};