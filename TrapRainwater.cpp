// 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int mL = 0;
        int mR = 0;
        int left = 0;
        int right = height.size()-1;
        int water = 0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=mL){
                    mL = height[left];
                }
                else{
                    water += mL - height[left];
                }
                left++;
            }
            else{
                if(height[right]>=mR){
                    mR = height[right];
                }
                else{
                    water += mR - height[right];
                }
                right--;
            }
        }
        return water;
    }
};
