
class Solution {
public:
    int trap(vector<int>& h) {
        int r=h.size()-1,l=0,rmax=0,lmax=0,res=0;
        
        while (l<r)
        {
            if (l<r)
            {
                if (h[l]<h[r])
                {
                    if (h[l]>lmax) lmax=h[l++];
                    else res += lmax-h[l++];                    
                }
                else {
                    if (h[r]>rmax) rmax=h[r--];
                    else res += rmax-h[r--];                                    
                }
            }
        }
        return res;
    }
};