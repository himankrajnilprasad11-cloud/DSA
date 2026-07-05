class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int Num = 0;
        while (x > Num) {
            Num = (Num * 10) + (x % 10);
            x /= 10;
        }
        return x == Num || x == Num/ 10;
    }
};