#include <string>
#include <vector>
using namespace std;

/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 * Example 2:
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 * Note:
 * All given inputs are in lowercase letters a-z.
 */

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if (strs.empty())
			return "";
		int i = 0;
		while (true)
		{
			if (i >= strs[0].size())
				return strs[0];
			char c = strs[0][i];
			for (auto &s : strs)
			{
				if (i >= s.size())
					return s;
				if (s[i] != c)
					return string(s.begin(), s.begin() + i);
			}
			++i;
		}
		return "";
	}
};