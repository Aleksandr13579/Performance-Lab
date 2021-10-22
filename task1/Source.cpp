#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

int main(int argC, char *argV[])
{
	std::ifstream file1(argV[1]);
	assert(file1.is_open() && "File is not open!");

	int n, m, iter = 0;
	while (file1 >> n >> m)
	{

		std::vector<int> vec;
		std::string str;

		for (int i = 0; i < n; ++i) vec.push_back(i + 1);

		while (vec.size() > 0)
		{
			str.push_back('0' + vec[iter]);

			if (m + (iter - 1) >= vec.size())
				iter = std::abs(int(vec.size()) - iter - m + 1);
			else
				iter += m - 1;

			if (vec[iter] == 1) break;
		}
		cout << str << endl;
	}
	return 0;
}