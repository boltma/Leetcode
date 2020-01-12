#include <string>
#include <vector>
using namespace std;

/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 * Example 2:
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 */

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		if (s.length() < 2)
			return 0;
		vector<int> v(s.length());
		int max = 0;
		v[0] = 0;
		if (s[0] == '(' && s[1] == ')')
		{
			v[1] = max = 2;
		}
		for (int i = 2; i < s.length(); ++i)
		{
			if (s[i] == '(')
			{
				v[i] = 0;
			}
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
				{
					v[i] = v[i - 2] + 2;
				}
				else
				{
					int j = i - 1 - v[i - 1];
					if(j >= 0 && s[j] == '(')
						v[i] = v[i - 1] + 2 + (j >= 1 ? v[j - 1] : 0);
					else v[i] = 0;
				}
				if (v[i] > max)
					max = v[i];
			}
		}
		return max;
	}
	// int longestValidParentheses(string s)
	// {
	// 	int max = 0;
	// 	for (int i = 0; i < s.length(); ++i)
	// 	{
	// 		int k = 0, m = 0;
	// 		for (int j = i; j < s.length(); ++j)
	// 		{
	// 			char c = s[j];
	// 			if (c == '(')
	// 			{
	// 				++k;
	// 				++m;
	// 			}
	// 			if (c == ')')
	// 			{
	// 				if (!k)
	// 				{
	// 					m = 0;
	// 				}
	// 				else
	// 				{
	// 					--k;
	// 					++m;
	// 					if (!k && m > max)
	// 						max = m;
	// 				}
	// 			}
	// 		}
	// 	}
	// 	return max;
	// }
};