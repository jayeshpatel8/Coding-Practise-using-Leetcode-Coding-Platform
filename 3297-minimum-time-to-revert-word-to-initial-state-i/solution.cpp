class Solution {
public:
int minimumTimeToInitialState(const string &word, int k) {
    int res = 1;
    for (; k * res < word.size(); ++res)
        if (equal(begin(word) + res * k, end(word), begin(word)))
            break;
    return res;
}
};
