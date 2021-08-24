class Solution {
public:

    vector<int> recoverArray(int n, vector<int>& sums) {
        /* adding element to set gives clues how to seperate it
          for {1,2} -> {0},{1},{2},{1,2}
               diff 1 -> {0} {2} , set not having diff element in it
               diff 2-0=2 -> {0} , set not having diff element in it
               as we always found empty set{0}, that means its posive diff else negative (X-diff = 0 {empty set}, if diff is -ve => X = diff as we got this empty set by subtracting from it s[2] = s[1] + (-diff))
        */
        
        sort(begin(sums), end(sums));
        int N = sums.size(), len=1;
        vector<int> ans, without(N/2),with(N/2);
        while(n--){
            int diff = sums[1] - sums[0] ,i=0,j=-1,pos=0,k=0;
            
            for(int i = 0; i<N; i++){
                if (k<=j && with[k]==sums[i]) {k++; continue;}
                pos += (sums[i]==0); 
                without[++j] = sums[i];
                with[j] = sums[i]+diff;
             }
            if(pos) {swap(sums, without);ans.push_back(diff);}
            else {ans.push_back(-diff); swap(sums, with);}
            
            N /=2;
        }
        return ans;
    }
};