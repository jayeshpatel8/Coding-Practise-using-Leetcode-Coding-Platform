class Solution {
public:
    string pushDominoes(string dom) {
        bool changed=true;
        string a = 'L' + dom + 'R';

        for (int i=0; i<a.size(); i++){
            if (a[i] != '.') continue;
            int i1=i-1,j1=i+1;
            while ( j1 < a.size() && a[j1] =='.') j1++;
            if ( a[i1]=='L'){
                i=j1;
                if (a[j1]=='L')                     
                    while(i1<--j1) a[j1]='L' ;              
            }
            else{
                if (a[j1]=='R') 
                    while(i < j1) a[i++]='R';                
                else{
                    i=j1;
                    i1++,--j1;
                    while(i1<j1) a[i1++]='R',a[j1--]='L';
                }
            }
        }

        return a.substr(1,dom.size());
    }
};