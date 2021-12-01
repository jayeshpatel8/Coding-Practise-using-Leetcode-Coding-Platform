class Solution {
public:
    int minimumBuckets(string street) {
        int i=0,N = street.size(),j=0;
        if (N==1 && street[0]=='H' ) return -1; 
        for (; i<N; i++)
            if (street[i]=='H')
                break;
        for ( ; i<N; i++){
            if (street[i] == 'H'){
                if (i+1<N && street[i+1]=='.'){
                    if (i==0 || street[i-1] != '-'){
                        street[i+1] = '-';
                        j++;
                    }
                    
                }
                else if (i>0 && street[i-1] == '.')
                    j++;
                else if (i==0 || street[i-1]=='H')
                    return -1;
            }
        }
        return j;
    }
};