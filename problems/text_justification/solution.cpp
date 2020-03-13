class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int w =words.size();
        vector<string> res;
        int j=0;
        while(j<w){
            
            int sl=0;int i=0; 
            for (; i+j<w && sl+i+words[j+i].size() <= maxWidth; i++){
                sl+=words[j+i].size();                
            }
           
            int space=1,extra=0;
            if(i!=1 && i+j !=w){
                space = (maxWidth-sl)/(i-1);
                extra = (maxWidth-sl)%(i-1);
            }
            string r(words[j]);
            for(int k=1; k<i;k++){
                r+=string(space,' ');
                if (extra-->0) r+=string(1,' ');
                r+=words[j+k];
            }
            if (r.size()<maxWidth)
                r+=string(maxWidth-r.size(),' ');
            res.push_back(r);
            j +=i;         
        }
        
        return res;
    }
};