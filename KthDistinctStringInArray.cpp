// 2053. Kth Distinct String in Array
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        for(const string& c:arr){
            map[c]++;
        }
        vector<string> results;
        for(const string& m : arr){
            if(map[m] == 1){
                results.push_back(m);
            }
        }

        return results.size() < k ? "" : results[k-1];
    }
};
