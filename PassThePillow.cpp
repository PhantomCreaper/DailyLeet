// 2582. Pass The Pillow
class Solution {
public:
    int passThePillow(int n, int time) {
        int index = time / (n - 1);
        return index % 2 == 0 ? (time % (n-1) + 1) : (n - time % (n-1));
    }
};
