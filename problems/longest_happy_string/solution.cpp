class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a)pq.push({a,'a'});
        if(b)pq.push({b,'b'});
        if (c) pq.push({c,'c'});
        string ans;
        int sz=0;
        while(!pq.empty()){
           pair<int,char> t  = pq.top(); pq.pop();
            
           if (sz < 2){
               ans +=t.second; sz++;
               t.first--;
           }
            else{
                if (t.second != ans[sz-1] || (t.second != ans[sz-2])){
                   ans +=t.second; sz++;
                   t.first--;                   
                }
                else {
                    if (pq.empty()) return ans;
                    else{
                        pair<int,char> t2  = pq.top(); pq.pop();
                        ans +=t2.second; sz++;
                        t2.first--;
                        if (t2.first) pq.push(t2);
                    }
                }
            }
           if (t.first) 
            pq.push(t);             
        }
        return ans;
    }
        /*
        string longestDiverseString(int a, int b, int c) {
        int sz = a+b+c, acnt=0,bcnt=0,ccnt=0;
        string ans;
        for (int i=0; i<sz; i++){
            if ((a >= b && a>=c && acnt != 2) || ((bcnt==2 || ccnt==2) && a>0))            
                ans +='a', acnt++, bcnt=ccnt=0,a--;
            else if ((b >= a && b>=c && bcnt != 2) || ((acnt==2 || ccnt==2) && b>0))            
                ans +='b', bcnt++, acnt=ccnt=0,b--;
            else if ((c >= b && c>=a && ccnt != 2) || ((bcnt==2 || acnt==2) && c>0))            
                ans +='c', ccnt++, bcnt=acnt=0,c--;  
            else
                return ans;
        }
        return ans;
    }*/
};