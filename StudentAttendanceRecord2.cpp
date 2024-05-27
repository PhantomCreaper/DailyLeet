// 552. Student Attendance Record II
#include <vector>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(2, vector<long long>(3, 0)));
        
        dp[0][0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int a = 0; a < 2; ++a) {
                for (int l = 0; l < 3; ++l) {
                    dp[i][a][0] = (dp[i][a][0] + dp[i - 1][a][l]) % MOD;

                    if (a > 0) {
                        dp[i][a][0] = (dp[i][a][0] + dp[i - 1][a - 1][l]) % MOD;
                    }

                    if (l < 2) {
                        dp[i][a][l + 1] = (dp[i][a][l + 1] + dp[i - 1][a][l]) % MOD;
                    }
                }
            }
        }
        
        long long result = 0;
        for (int a = 0; a < 2; ++a) {
            for (int l = 0; l < 3; ++l) {
                result = (result + dp[n][a][l]) % MOD;
            }
        }
        
        return result;
    }
};
