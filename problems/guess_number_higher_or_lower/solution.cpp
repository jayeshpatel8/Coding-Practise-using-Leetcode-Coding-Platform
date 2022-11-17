/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 0, mid = (start + (n - start)/2);
        while (auto a  = guess(mid)){
            if ((a > 0)){
                start=  mid +1;
            }
            else
            n = mid-1;
            mid = (start + (n - start)/2);
        }
        return mid;
    }
};