class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        // Step 1: Count frequencies using an ordered map
        // This automatically sorts the unique cards from smallest to largest
        map<int, int> counts;
        for (int card : hand) {
            counts[card]++;
        }

        // Step 2: Keep pulling from the "top" (the smallest available card)
        while (!counts.empty()) {
            // map.begin() always points to the smallest key remaining
            int first = counts.begin()->first;
            
            // Try to form a consecutive group starting from 'first'
            for (int i = 0; i < groupSize; ++i) {
                int currentCard = first + i;
                
                // If the required consecutive card doesn't exist, we can't form the group
                if (counts.find(currentCard) == counts.end()) {
                    return false;
                }
                
                // Decrement the count
                counts[currentCard]--;
                
                // Erase the key if its count hits zero
                if (counts[currentCard] == 0) {
                    counts.erase(currentCard);
                }
            }
        }

        return true;
    }
};
