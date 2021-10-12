/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1, r=n, m = l + (r-l)/2, p ;
        
        while(p = guess(m)){
            if (p > 0){
                l = m+1;
            }
            else 
                r = m-1;
            m = l + (r-l)/2;
        }
        return m;
    }
};