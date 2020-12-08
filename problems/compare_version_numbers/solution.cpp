class Solution {
public:
    int compareVersion(string v1, string v2) {
     // extract the rev, 
        // remove leading zero
        int l1 = v1.length(), l2=v2.length();
        int i=0,j=0;
        int result = -1;
        while (i<l1 || j <l2)
        {
            int a =  getrev(v1,i);
            int b =  getrev(v2,j);
            
            if (a==b) result = 0;
            else
                if (a==-1 && b==0) continue;
                else if (b==-1 && a==0) continue;
                else if (a < b) return -1;
                else return 1;
        }
        return 0;

    }
    int getrev(string v1, int & r){
        if (r >= v1.size() ) return -1;
        int num=0;
        while (r < v1.size() ){
            int c = v1[r++];
            if ( c != '.')
                num = c - '0' + (num * 10);
            else
                break;
        }
        return num;
    }
};