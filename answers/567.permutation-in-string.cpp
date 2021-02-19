#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

class Solution
{
public:
    bool checkInclusion(const string &s1, const string &s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }

        int count1[26] = {0}, count2[26] = {0};

        int windowSize = s1.size();
        for (int i = 0; i < windowSize; ++i)
        {
            ++count1[s1[i] - 'a'];
            ++count2[s2[i] - 'a'];
        }

        for (int i = windowSize; i < s2.size(); ++i)
        {
            if (memcmp(count1, count2, sizeof(count1)) == 0)
            {
                return true;
            }
            ++count2[s2[i] - 'a'];
            --count2[s2[i - windowSize] - 'a'];
        }

        return (memcmp(count1, count2, sizeof(count1)) == 0);
    }
};

int main()
{
    Solution so;
    string s1("ab"), s2("eidboaoo");

    cout << (so.checkInclusion(s1, s2) ? "true" : "false") << endl;

    return 0;
}
