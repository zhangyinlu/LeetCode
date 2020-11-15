#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<int> partitionLabels(string &&S)
    {
        return partitionLabels(S);
    }
    vector<int> partitionLabels(const string &S)
    {
        int last[26];
        int length = S.size();
        for (int i = 0; i < length; i++)
        {
            last[S[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++)
        {
            end = max(end, last[S[i] - 'a']);
            if (i == end)
            {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};
template <class T>
void printVec(vector<T> &vec)
{
    cout << "[";
    for (auto &tmp : vec)
    {
        cout << tmp << ",";
    }
    cout << "]" << endl;
}
int main()
{
    Solution solution;
    auto res = solution.partitionLabels("ababcbacadefegdehijhklij");
    printVec(res);
    return 0;
}
