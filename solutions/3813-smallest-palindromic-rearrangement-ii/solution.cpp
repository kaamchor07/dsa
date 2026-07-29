class Solution {
private:
    // Computes nCr capped at 'limit' to prevent overflow
    long long nCr(int n, int r, long long limit) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r; // Symmetry optimization
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - r + i) / i;
            if (res > limit) return limit + 1; // Cap immediately
        }
        return res;
    }

    // Computes total multinomial permutations for remaining character counts
    long long getPermutations(const vector<int>& counts, int L, long long k) {
        long long total = 1;
        int remaining = L;
        
        for (int count : counts) {
            if (count == 0) continue;
            
            total *= nCr(remaining, count, k);
            if (total > k) return k + 1; // Cap total early
            
            remaining -= count;
        }
        return total;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> count(26, 0);
        
        // Step 1: Count character frequencies
        for (char c : s) {
            count[c - 'a']++;
        }

        // Handle middle character for odd length
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 == 1) {
                mid_char = 'a' + i;
                count[i]--; // Reduce to even count for half-length construction
                break;
            }
        }

        // Half-length frequencies
        vector<int> half_count(26, 0);
        int half_len = n / 2;
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }

        // Step 2: Check if total permutations are less than k
        long long total_ways = getPermutations(half_count, half_len, k);
        if (total_ways < k) {
            return "";
        }

        // Step 3: Construct the first half lexicographically
        string first_half = "";
        int remaining_len = half_len;

        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half_count[c] == 0) continue;

                // Hypothetically place character 'a' + c
                half_count[c]--;
                
                // Count permutations possible with remaining slots
                long long ways = getPermutations(half_count, remaining_len - 1, k);

                if (k <= ways) {
                    // Correct character found! Keep choice and move to next position
                    first_half += (char)('a' + c);
                    remaining_len--;
                    break;
                } else {
                    // Skip 'ways' permutations and backtrack count
                    k -= ways;
                    half_count[c]++;
                }
            }
        }

        // Step 4: Mirror the string to build full palindrome
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());

        if (n % 2 != 0) {
            return first_half + mid_char + second_half;
        } else {
            return first_half + second_half;
        }
    }
};
