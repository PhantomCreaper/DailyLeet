// 1255. Maximum Score Words Formed by Letters.
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letterCount(26, 0);
        for(char c : letters){
            letterCount[c -'a']++;
        }
        return backtrack(words, letterCount, score, 0);
    }

    int backtrack(vector<string>& words, vector<int>& letterCount, vector<int>&score, int index){
        if(index == words.size()){
            return 0;
        }
        int maxScore = backtrack(words, letterCount, score, index+1);
        
        vector<int> wordCount(26, 0);
        int currentScore = 0;
        bool isWord = true;
        for(char c : words[index]){
            wordCount[c - 'a']++;
            currentScore += score[c-'a'];
            if(wordCount[c-'a'] > letterCount[c-'a']){
                isWord = false;
            }
        }

        if(isWord){
            for(char c : words[index]){
                letterCount[c-'a']--;
            }
            maxScore = max(maxScore, currentScore + backtrack(words, letterCount, score, index+1));
            for(char c : words[index]){
                letterCount[c-'a']++;
            }
        }
        return maxScore;
    }
};
