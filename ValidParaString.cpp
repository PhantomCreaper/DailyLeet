//678 Valid Parantheses String
class Solution {
public:
    bool checkValidString(string s) {
        int leftMax = 0;
        int leftMin = 0;
        for(char c:s){
            if(c == '('){
                leftMax++;
                leftMin++;
            } else if(c==')'){
                leftMax--;
                leftMin = max(leftMin-1, 0);
            } else{
                leftMax++;
                leftMin = max(leftMin-1, 0);
            }
            if(leftMax<0){
                return false;
            }
        }
        return leftMin==0;
        
    }
};
