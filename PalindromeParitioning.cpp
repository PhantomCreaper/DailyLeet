// 131. Palindrome Partitioning.
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        partitionPalindrome(s, result, 0, current);
        return result;
    }

    void partitionPalindrome(const string& s, vector<vector<string>>& result, int index, vector<string>& current){
        if(index == s.size()){
            result.push_back(current);
            return;
        }

        for(int i = index; i < s.size(); i++){
            if(isPalin(s, index, i)){
                current.push_back(s.substr(index, i - index + 1));
                partitionPalindrome(s, result, i+1, current);
                current.pop_back();
            }
        }
    }

    bool isPalin(const string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
