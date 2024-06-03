// 2486. Append Characters To String to Make Subsequence.
class Solution {
public:
    int appendCharacters(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = s.size();
        int m = t.size();
        int j = 0;
        for(int i = 0; i < n && j < m; i++){
            if(s[i] == t[j]){
                j++;
            }
        }
        return m-j;
    }
};
