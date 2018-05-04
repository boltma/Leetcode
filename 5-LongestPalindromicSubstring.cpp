#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Example 1:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 * Example 2:
 * Input: "cbbd"
 * Output: "bb"
 */

class Solution
{
public:
	string longestPalindrome (string s)
	{
		string r = "$#";
		for (int i = 0; i < s.length(); ++i)
		{
			r += s[i];
			r += '#';
		}
		r += '!';
		int max_len = -1, len = r.length() - 1, m = 0, t = 0, id = 0;
		vector<int> v (len, 1);
		for (int i = 1; i < len; ++i)
		{
			if (i < m)
				v[i] = min (v[2 * t - i], m - i);
			while (r[i + v[i]] == r[i - v[i]])
				++v[i];
			if (v[i] - 1 > max_len)
			{
				max_len = v[i] - 1;
				id = i - max_len;
			}
			if (v[i] + i > m)
			{
				m = v[i] + i;
				t = i;
			}
		}
		return s.substr ( id / 2, max_len);
	}
};