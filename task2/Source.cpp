#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

int main(int argC, char *argV[])
{
	assert(!(argC < 2) && "No arguments passed!");

	std::ifstream file1(argV[1]);
	std::ifstream file2(argV[2]);

	assert(file1.is_open() && "File1 is not open!");
	assert(file2.is_open() && "File2 is not open!");

	int x, y, radius, x0, y0, i;

	file1 >> x >> y >> radius;
	while (file2 >> x0 >> y0)
	{
		if (sqrt(pow((x - x0), 2) + pow((y - y0), 2)) < radius) 
			std::cout << 1 << std::endl;
		else if (sqrt(pow((x - x0), 2) + pow((y - y0), 2)) == radius) 
			std::cout << 0 << std::endl;
		else  
			std::cout << 2 << std::endl;
	}

	return 0;
}