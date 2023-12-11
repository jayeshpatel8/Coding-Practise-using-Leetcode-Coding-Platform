class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int f = arr.size()/4;   
        if (f==0) return arr[0];
        int c=0,p=-1;
        for (auto i : arr){
            if (i != p) p = i,c=1;
            else{
                if (++c > f) return i;
            } 
            
        }

        return 0;
    }
};
