class Solution {
public:
    bool isPalindrome(int x) {
        // Early exits
        if (x < 0 || (x % 10 == 0 && x != 0)) 
            return false;

        int reversedHalf = 0;
        // Build reversedHalf until it’s >= the remaining front half
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        // For odd digit counts, drop the middle digit by reversedHalf/10
        return (x == reversedHalf) 
            || (x == reversedHalf / 10);
    }
};

