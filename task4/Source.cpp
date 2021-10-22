#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

int main(int argC, char *argV[])
{
	int n; 
	int mid, count = 0;
	std::vector<int> nums;
	std::ifstream file1(argV[1]);

	while (file1 >> n) 
		nums.push_back(n);
	std::sort(nums.begin(), nums.end());

	if (nums.size() % 2 == 0)
		mid = int(nums.size()) / 2;
	else
		mid = int(nums.size()) / 2 + 1;

	for (auto &i : nums)
	{
		while (i != nums[mid])
		{
			if (i < nums[mid]) ++i;
			else --i;

			++count;
		}
	}

	std::cout << count;

	return 0;
}