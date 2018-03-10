/*
  LeetCode.com
  Solution for Distribute Candies
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 10/03/2018
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int type = 0;

        map<int, bool> jar;
        for (size_t i = 0; i < candies.size(); ++i) {
            if (!jar[candies[i]]) {
                jar[candies[i]] = true;
                ++type;
            }
        }

        if (type < (candies.size() >> 1))
            return type;
        else
            return candies.size() >> 1;
    }
};

int main() {
    Solution s;
    vector<int> v = {1,1,2,3};
    printf("%d\n", s.distributeCandies(v));

    return 0;
}
