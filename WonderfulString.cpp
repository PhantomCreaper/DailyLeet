// 1915. Number of Wonderful Strings
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        vector<int>count(1024,0);
        count[0]=1;
        int mask=0;
        for(auto c: word)
        {
            mask= mask ^ (1<<(c-'a'));
            ans+=count[mask];
          
            for(int i=0;i<10;i++)
            {
               int newmask = mask ^ (1<<i);
                ans+=count[newmask];
            }
            count[mask]++;
        }
        return ans;
    }
};
