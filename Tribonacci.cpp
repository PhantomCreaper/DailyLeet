// 1137. Nth Tribonnaci number
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1 || n ==2){
            return 1;
        }
        int n1 = 0;
        int n2 = 1;
        int n3 = 1;
        int next;
        for(int i = 3; i<=n ; i++){
            next = n1 + n2 + n3;
            n1 = n2;
            n2 = n3;
            n3 = next;
        }
        return next;
    }
};
