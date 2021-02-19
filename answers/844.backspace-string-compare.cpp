#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string &&S, string &&T)
    {
        return backspaceCompare(S, T);
    }
    bool backspaceCompare(const string &S, const string &T)
    {
        return backspaceString(S) == backspaceString(T);
    }
    string backspaceString(const string &str)
    {
        string ret;
        for (auto ch : str)
        {
            if (ch != '#')
            {
                ret.push_back(ch);
            }
            else if (!ret.empty())
            {
                ret.pop_back();
            }
        }
        return ret;
    }
};
int main()
{
    Solution solution;
    cout << (solution.backspaceCompare("ab#c", "ad#c") ? "true" : "false") << endl;
    return 0;
}
