// 506. Relative Ranks

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
    int n = score.size();
    vector<pair<int, int>> score_with_index;
    
    for (int i = 0; i < n; ++i) {
        score_with_index.push_back({score[i], i});
    }
    
    sort(score_with_index.begin(), score_with_index.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.first > b.first;
         });
    
    vector<string> ranks(n);
    
    for (int i = 0; i < n; ++i) {
        if (i == 0) ranks[score_with_index[i].second] = "Gold Medal";
        else if (i == 1) ranks[score_with_index[i].second] = "Silver Medal";
        else if (i == 2) ranks[score_with_index[i].second] = "Bronze Medal";
        else ranks[score_with_index[i].second] = to_string(i + 1);
    }
    
    return ranks;
}
};
