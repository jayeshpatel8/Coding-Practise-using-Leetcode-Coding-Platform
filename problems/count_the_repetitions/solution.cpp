class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        int N = s2.size();
        unordered_map<int,int>  index;
        int count[n1+1],idx=0, cnt=0;
        memset(count,0,sizeof(count));
        index[0]=0;
        for (int i=1; i<=n1; i++){
            for(int j=0; j<s1.size(); ++j){
                if (s1[j] == s2[idx]){
                    idx++;
                    if( idx == N) 
                        ++cnt, idx=0;
                }
            }
        
            count[i] = cnt;
            
            for ( int container = 0; container<i; container++){
                if (index[container]==idx){
                    int prev_cnt= count[container];
                    int cur_cnt = (n1-container)/(i-container) * (count[i]-prev_cnt) ;
                    int rem_cnt = count[container + (n1-container)%(i-container)] -prev_cnt;
                    return (prev_cnt + cur_cnt + rem_cnt)/n2;
                }
            }
            index[i] = idx;
        }
        return count[n1]/n2;
    }
};
/*
aba  

aba


aaa

aa

aa

aaa
*/