#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isLongPressedName(string &&name, string &&typed)
    {
        return isLongPressedName(name, typed);
    }
    bool isLongPressedName(const string &name, const string &typed)
    {
        int nameLength = name.length(), typedLength = typed.length();
        if (nameLength > typedLength)
        {
            return false;
        }

        int i = 0, j = 0;
        while (j < typedLength)
        {
            if (i < nameLength && name[i] == typed[j])
            {
                ++i;
                ++j;
            }
            else if (j > 0 && typed[j] == typed[j - 1])
            {
                ++j;
            }
            else
            {
                return false;
            }
        }
        return (i == nameLength);
    }
};

int main()
{
    Solution solution;
    cout << (solution.isLongPressedName("adsb", "aadsbb") ? "true" : "false") << endl;
    return 0;
}