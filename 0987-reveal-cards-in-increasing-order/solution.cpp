class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(begin(deck),end(deck));
        int n  =  deck.size();

        queue<int> q;
        q.push(deck[n-1]);
        for (int i=n-2; i>=0; i--)   {
            auto f = q.front();q.pop();
            q.push(f);
            q.push(deck[i]);
        }
        vector<int> ans;
        while (!q.empty()){
            ans.push_back(q.front());q.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
