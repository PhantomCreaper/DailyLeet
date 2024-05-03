// 165. Compare version Numbers
class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        std::vector<int> nums1 = splitAndConvert(version1);
        std::vector<int> nums2 = splitAndConvert(version2);
        
        int n1 = nums1.size(), n2 = nums2.size();
        int maxLen = std::max(n1, n2);
        
        for (int i = 0; i < maxLen; ++i) {
            int v1 = i < n1 ? nums1[i] : 0;
            int v2 = i < n2 ? nums2[i] : 0;
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
        }
        
        return 0;
    }
    
private:
    std::vector<int> splitAndConvert(const std::string &version) {
        std::vector<int> nums;
        int num = 0;
        int n = version.length();
        
        for (int i = 0; i <= n; ++i) {
            if (i == n || version[i] == '.') {
                nums.push_back(num);
                num = 0;
            } else {
                num = num * 10 + (version[i] - '0');
            }
        }
        
        return nums;
    }
};
