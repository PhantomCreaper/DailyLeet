// 1152. Magnetic Force Between Two Balls
class Solution {
public:
    bool canPlace(vector<int>& position, int m, int dist){
        int count = 1;
        int pos = position[0];

        for(int i = 0; i < position.size(); i++){
            if(position[i] - pos >= dist){
                count++;
                pos = position[i];
            }
            if(count >= m){
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 0;
        int high = position.back() - position.front();
        int result = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canPlace(position, m, mid)){
                result = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return result;

    }
};
