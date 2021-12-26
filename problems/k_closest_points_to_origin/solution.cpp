class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        quickSel(begin(points),end(points),k,[](vector<int> & a, vector<int> &b){return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);});
        points.resize(k);
        return points;
    }
    template<class it, class Compare> void quickSel(it first, it last, int k, Compare cmp){
        it p = part(first,last, cmp );
        if (p-first +1 == k) return;
        if (p-first +1 < k) quickSel(p+1,last,k - (p - first + 1), cmp);
        else
            quickSel(first,p, k,cmp);
    }
    template<class it, class Compare> it part(it first, it last, Compare cmp){
        auto end = prev(last);
        auto pivot = *end;
        while (first < end){
            while(cmp(*first,pivot)) first++;
            while(cmp(pivot,*end)) --end;
            if(first < end){
                swap(*first,*end);
                if (!cmp(*first, *end))
                    end--;
            }
        }
        return first;
    }
    vector<vector<int>> kClosest2(vector<vector<int>>& points, int k) {
        nth_element(begin(points),begin(points)+k-1,end(points), [](auto &a , auto &b){ return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);});
        points.resize(k);
        return points;
    }
};