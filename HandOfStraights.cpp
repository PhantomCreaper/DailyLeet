// 846. Hand Of Straights
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        map<int, int> count;
        for(int card:hand){
            count[card]++;
        }

        for(auto i = count.begin(); i != count.end(); i++){
            int card = i->first;
            int c = i->second;
            if(c > 0){
                for(int i = 0; i < groupSize; i++){
                    if(count[card + i] < c){
                        return false;
                    }
                    count[card+i] -= c;
                }
            }
        }
        return true;

        return true;
    }
};
