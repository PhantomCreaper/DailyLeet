// 1002 Minimum Characters
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26, INT_MAX);
        vector<string> results;
        for(const string& word:words){
            vector<int> cf(26, 0);
            for(char c:word){
                cf[c-'a']++;
            }
            for(int i = 0; i < 26; i++){
                freq[i] = min(freq[i], cf[i]);
            }
        }
        for(int  i = 0; i < 26; i++){
            while(freq[i]>0){
                results.push_back(string(1, 'a' + i));
                freq[i]--;
            }
        }
        return results;
    }
};
