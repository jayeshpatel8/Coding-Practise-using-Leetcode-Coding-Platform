class Solution {
public:
    string pushDominoes(string dom) {
        // ...   LL RR  
        //  .LX  
        //  XR.
        // R.(.).L
        int prev='L', j=-1,i=0;
        while( i < dom.size()){
            if ( dom[i] != '.') 
            {
                if (dom[i]== 'R'){
                    if (prev=='R') while(++j<i) dom[j] = 'R';
                    prev='R';
                }
                else{
                    // 'L'
                    if (prev=='L') while(++j<i) dom[j] = 'L';
                    else {
                        int s = ++j, e=i-1;
                        while(s<e) dom[s++]='R', dom[e--]='L';
                    }
                    prev='L';
                }
                j=i;
            }
            i++;
        }
        if (prev=='R')
            while (j<i) dom[++j]='R';
        return dom;
    }
};