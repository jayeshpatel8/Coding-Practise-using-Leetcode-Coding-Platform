class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        int l1 =s1.length(), l2=s2.length();
        
        int i=0;
        int j=i;
          while (j <l1 && j < l2 && s1[j]== s2[j])  {
              if (s1[j]== ' '){
                  i=j+1;
              }
              j++;
          }
        if (j==l1 &&  (j==l2 )) return true;
        if (j==l1 ){
            return ( j<l2 && s2[j]==' ');
        }
        if (j==l2 ){
            return ( j<l1 && s1[j]==' ');
        }            
        
        while (--l1>=i && --l2>=i && s1[l1]==s2[l2] ) ;
        if (l1<i || l2<i) return true;
        return false;
    }
};