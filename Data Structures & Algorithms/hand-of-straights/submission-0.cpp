class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        
        map<int,int> h; 
        for(auto x: hand){
            if(h.contains(x)){
                h[x]++;
            }
            else{
                h[x] = 1;
            }
        }
        
        // Loop until all cards have been placed into groups
        while(!h.empty()) {
            // The smallest available card MUST be the start of our next group
            int startCard = h.begin()->first; 
            
            // Explicitly look for the consecutive sequence
            for(int i = 0; i < groupSize; i++) {
                int currentCard = startCard + i;
                
                // If we don't have the required consecutive card, it's impossible
                if(!h.contains(currentCard)) {
                    return false; 
                }
                
                // Use the card and remove it from the map if its count hits 0
                h[currentCard]--;
                if(h[currentCard] == 0) {
                    h.erase(currentCard);
                }
            }
        }
        return true;
    }
};
