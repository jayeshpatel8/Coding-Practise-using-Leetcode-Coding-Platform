class Solution {
public:
    vector<string> splitMessage(string me, int limit) {
        int l=1 , len=me.size(), r=9;

        while (l<=len){
            int m=r;
            int total = 0 ,l1=1, next=9, l2= (to_string(m).size());
            //104
            total = (limit -3 -l2) * m;
            
            for (int i=1; i<=m;i++){
                //total += (limit -3 -l2 - l1) ;
                total -= l1;
                if (i==next){
                    next = next * 10 + 9;
                    l1++;
                }
            }
            if (total >= len)break;
            l*=10;
            r = min(len+1, r*10+9);

        }
        vector<string> ans;
        if (l<=len){
            while (l<r){
                int m = (l+r)/2;
                int total = 0 ,l1=1, next=9, l2= (to_string(m).size());
                //104
                total = (limit -3 -l2) * m;
                
                for (int i=1; i<=m;i++){
                    //total += (limit -3 -l2 - l1) ;
                    total -= l1;
                    if (i==next){
                        next = next * 10 + 9;
                        l1++;
                    }
                }
                        
                
                if (total < len) l=m+1;
                else r=m;
                
            }
            
            if (r==0) return {};
            
            
            for (int j=0,i=1; i<=r; i++){
                string suf = "<" + to_string(i)+ "/" + to_string(r)+">";
                ans.push_back(me.substr(j,limit-suf.size()) + suf);
                j += limit - suf.size();
            }
        }
        return ans;
    }
};