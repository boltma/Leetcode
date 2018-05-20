#include <string>
using namespace std;

/**
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

class Solution
{
public:
	int lengthOfLongestSubstring (string s)
	{
		bool c[256] = {false};
		int i = 0, j = 0, max = 0, cur = 0;
		while (j != s.size())
		{
			if (c[s[j] - '\0'])
			{
				c[s[i++] - '\0'] = false;
				cur--;
			}
			else
			{
				c[s[j] - '\0'] = true;
				cur++;
				if (cur > max)
					max = cur;
				j++;
			}
		}
		return max;
	}
};