// 726. Number of Atoms
class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        map<string, int> currentMap;
        int n = formula.size();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                stk.push(currentMap);
                currentMap.clear();
                i++;
            } else if (formula[i] == ')') {
                map<string, int> tempMap = currentMap;
                currentMap = stk.top();
                stk.pop();
                i++;
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }
                count = max(count, 1);
                for (auto &p : tempMap) {
                    currentMap[p.first] += p.second * count;
                }
            } else {
                string atom;
                atom += formula[i++];
                while (i < n && islower(formula[i])) {
                    atom += formula[i++];
                }
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }
                count = max(count, 1);
                currentMap[atom] += count;
            }
        }

        string result;
        for (auto it = currentMap.begin(); it != currentMap.end(); ++it) {
            result += it->first;
            if (it->second > 1) {
                result += to_string(it->second);
            }
        }
        return result;
    }
};
