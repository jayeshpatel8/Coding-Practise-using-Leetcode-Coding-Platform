class Solution {
public:
    string largestMerge(string w1, string w2) {
        int l1=   w1.length(), l2 = w2.length();
        string r;
        int i=0, j=0,k=-1,rank=0;
        //word1 = "abcabc", word2 = "abdcaba"
        for (; i<l1 && j <l2; ){
            if (w1[i] > w2[j]){
                r.push_back(w1[i++]);
            }else if (w1[i] < w2[j]){
                r.push_back(w2[j++]);
            }else{ // equal
                    int ii=i,jj=j;
                    while(ii<l1 && jj<l2 && w1[ii]==w2[jj]) ii++,jj++;
                    if (ii <l1 && jj < l2){
                        r.push_back( w1[ii] < w2[jj]? w2[j++]:w1[i++]);
                    }else if (jj<l2){
                        r.push_back(w2[j++]);
                    }else{
                        r.push_back(w1[i++]);                        
                    }
                
#if 0                
                if (!rank && i<= k){
                    r.push_back(w1[i++]);
                }else if (rank  && j<=k){
                    r.push_back(w2[j++]);
                }else { // find new rank
                    int ii=i,jj=j;
                    while(ii<l1 && jj<l2 && w1[ii]==w2[jj]) ii++,jj++;
                    if (ii <l1 && jj < l2){
                        rank = w1[ii] < w2[jj];
                        k = rank ? jj : ii;
                        r.push_back( rank? w2[j++]:w1[i++]);
                    }else if (jj<l2){
                        rank = 1; k = l2;
                        r.push_back(w2[j++]);
                    }else{
                        rank = 0; k = l1;
                        r.push_back(w1[i++]);                        
                    }
                }
#endif                
            }
        }
        while (i<l1)r.push_back(w1[i++]);
        while (j<l2)r.push_back(w2[j++]);
        return r;
    }
};