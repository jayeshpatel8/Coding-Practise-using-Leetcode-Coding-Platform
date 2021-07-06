class Solution {
public:
    //int map[100001];
    int minSetSize(vector<int>& arr) {
        int m = *max_element(begin(arr),end(arr)), mf=0;
        int map[m+1],freq[arr.size()+1];
        memset(map,0,sizeof(map));
        memset(freq,0,sizeof(freq));
        for (auto i : arr) {
            map[i]++;
            if (map[i]==1){
                freq[1]++;
            }else{
                freq[map[i]-1]--;
                freq[map[i]]++;
            }
            mf = max(mf,map[i]);
        }        
        int n = arr.size()/2,cnt=0;
        for (int i=mf; i>1;i--)
        {
            while(freq[i]){
                int  p = freq[i]* i;
                if ( p <=n){
                    n -= p;
                    cnt +=freq[i];
                    freq[i]=0;
                }else{       
                    int d = n/i + (n%i != 0);
                    n -=i * (d); 
                    return cnt+ d;
                }
                if (n <=0) return cnt;
            }   
        }
    
        return cnt+n;
    }
};