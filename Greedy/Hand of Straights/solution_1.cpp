class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }

        map<int, int> cardCount;
        for(auto card : hand){
            cardCount[card]++;
        }

        // since we are using ordered_map which is already sorted, that's why we are iterarting over map
        // If we sort the hand, then we can iterate on hand also 
        for(auto [card, count] : cardCount){
            while(cardCount[card] > 0){
                for(int i = 0; i < groupSize; i++){
                    if(cardCount[card + i] == 0){
                        return false;
                    }
                    cardCount[card + i]--;
                }
            }
        }
        return true;
    }
};

// Time: O(n log n) — each of the n cards is inserted and removed once, and every map operation takes log n.
// Space: O(n) — we store frequencies of up to n distinct cards.
