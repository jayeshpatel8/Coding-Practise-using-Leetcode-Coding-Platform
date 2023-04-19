
//Prerequisite :- https://leetcode.com/problems/longest-consecutive-sequence/


	
class Solution {
public:
vector<long long> maximumSegmentSum(vector<int>& v,vector<int>& q){
        long long cur=0,n=v.size();
        vector<long long>sum(n,0),count(n,0),ans(n,0);
        for(int i=n-1;i>=0;i--){
            ans[i]=cur;
            int x=q[i];
            
            long long leftsum=0,leftcount=0;
            if(x!=0) leftsum=sum[x-1],leftcount=count[x-1];
            
            long long rightsum=0,rightcount=0;
            if(x!=n-1) rightsum=sum[x+1],rightcount=count[x+1];
            
            long long cursum,curcount;
            cursum=v[x]+leftsum+rightsum;
            curcount=1+leftcount+rightcount;
            
            if(x!=0) sum[x-leftcount]=cursum,count[x-leftcount]=curcount;
            if(x!=n-1) sum[x+rightcount]=cursum,count[x+rightcount]=curcount;

            cur=max(cur,cursum);
        }
        return ans;
    }
    vector<long long> maximumSegmentSum2(vector<int>& nums, vector<int>& rq) {
        multiset<long long, greater<long long>> segsum;
        int N = nums.size();
        set<int> st{-1,N};
        vector<long long> ans, psum(N+1);
        for (int i=0; i<N; i++){
            psum[i+1] = psum[i] + nums[i];
        }
        segsum.insert(psum[N]);
        for (auto i : rq){
            auto next =  st.lower_bound(i);
            auto cur = prev(next);

            auto cur_sum  = psum[*next] - psum[*cur+1];
            segsum.erase(segsum.find(cur_sum));
            auto l  = psum[i]-psum[*cur+1],r = psum[*next]-psum[i+ 1];
            segsum.insert(l);
            segsum.insert(r);
            st.insert(i);

            ans.push_back(*begin(segsum));

        }
        return ans;
    }
};