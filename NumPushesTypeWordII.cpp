// 3016. Minimum Number of Pushes to Type Word II
class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> frequencyMap;
        for(char c : word) {
            frequencyMap[c]++;
        }
        
        vector<int> frequencies;
        for(auto& entry : frequencyMap) {
            frequencies.push_back(entry.second);
        }

        // Sort frequencies in descending order
        sort(frequencies.rbegin(), frequencies.rend());

        int result = 0;
        int position = 1;  // This indicates the number of presses needed for the current set of letters
        for(int i = 0; i < frequencies.size(); i++) {
            result += frequencies[i] * position;
            // Increment position after every 9 characters
            if((i + 1) % 8 == 0) {
                position++;
            }
        }

        return result;
    }
};
