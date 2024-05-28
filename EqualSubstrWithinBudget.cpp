// 1208. Get Equal Substrings Within Budget
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n = s.length();
        int l = 0, r = 0;
        int cost = 0;
        int length = 0;
        while(r<n){
            cost += abs(s[r] - t[r]);

            while(cost>maxCost){
                cost -= abs(s[l] - t[l]);
                l++;
            }

            length = max(length, r-l+1);
            r++;
        }
        return length;
    }
};
