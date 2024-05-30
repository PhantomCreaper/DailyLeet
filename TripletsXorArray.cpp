// 1442. Count Triplets That Can Form Two Array of Equal XOR
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = arr.size();
        vector<int> prefixXOR(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }
        
        int count = 0;
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i < k; ++i) {
                if (prefixXOR[i] == prefixXOR[k + 1]) {
                    count += (k - i);
                }
            }
        }
        
        return count;
    }
};
