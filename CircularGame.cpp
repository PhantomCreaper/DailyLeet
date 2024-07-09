// 1823. Find Winner of Circular Game
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends(n);
        iota(friends.begin(), friends.end(), 1);
        int point = 0;
        while(friends.size() > 1){
            point = (point + k - 1) % friends.size();
            friends.erase(friends.begin() + point);
        }
        return friends[0];
    }
};
