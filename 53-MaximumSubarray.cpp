#include <algorithm>
#include <vector>
using namespace std;

/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 *
 * Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 * Follow up:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

class Solution
{
public:
	/*
	int maxSubArrayFunc(vector<int> &nums, int left, int right)
	{
		if (left == right - 1)
			return nums[left];
		if (left >= right)
			return INT_MIN;
		int mid = (left + right) / 2;
		int k = max(maxSubArrayFunc(nums, left, mid), maxSubArrayFunc(nums, mid, right));
		int left_max = INT_MIN, right_max = INT_MIN;
		int sum = 0;
		for (int i = mid - 1; i >= left; --i)
		{
			sum += nums[i];
			if (sum > left_max)
				left_max = sum;
		}
		sum = 0;
		for (int i = mid; i < right; ++i)
		{
			sum += nums[i];
			if (sum > right_max)
				right_max = sum;
		}
		if (left_max + right_max > k)
			k = left_max + right_max;
		return k;
	}
	int maxSubArray(vector<int>& nums)
	{
		return maxSubArrayFunc(nums, 0, nums.size());
	}
	*/
	int maxSubArray(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		int max = nums[0];
		int k = 0;
		for (auto &i : nums)
		{
			k += i;
			if (k > max)
				max = k;
			if (k < 0)
				k = 0;
		}
		return max;
	}
};