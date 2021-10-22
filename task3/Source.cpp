#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;

int main(int argC, char *argV[])
{
	assert(!(argC < 2) && "No arguments passed!");

	std::ifstream TestJs(argV[1]);
	std::ifstream ValuesJs(argV[2]);
	std::ofstream Out;

	assert(TestJs.is_open() && "tests.json is not open!");
	assert(ValuesJs.is_open() && "values.json is not open!");

	string str1;
	string str2;

	string StrForSaveId;
	
	std::map<string, string> mapa;
	while (std::getline(ValuesJs, str1))
	{
		bool FoundId = false;
		bool FoundValue = false;
		string id;
		string value;
		for (int i = 0; i != str1.size() && str1.size() > 4; ++i)
		{
			if (str1[i] == 'i' && str1[i + 1] == 'd' && str1[i + 2] == '"')
			{
				i += 5;
				FoundId = true;
			}
			if (FoundId && str1[i] != ',')
				id += str1[i];

			if (str1[i] == 'u' && str1[i + 1] == 'e' && str1[i + 2] == '"')
			{
				i += 6;
				FoundValue = true;
			}
			if (FoundValue && str1[i] != '"')
				value += str1[i];
		}

		if (FoundId)
		{
			mapa[id] = "";
			StrForSaveId = id;
		}
		if (FoundValue) mapa[StrForSaveId] = value;
	}
;	
	std::map<string, string>::iterator it;
	Out.open("../report.json");
	while (std::getline(TestJs, str2))
	{
		bool FoundId = false;
		bool FoundValue = false;
		string id;
		string value;
		for (int i = 0; i != str2.size() && str2.size() > 4; ++i)
		{
			if (str2[i] == 'i' && str2[i + 1] == 'd' && str2[i + 2] == '"')
			{
				i += 5;
				FoundId = true;
			}
			if (FoundId && str2[i] != ',')
				id += str2[i];

			if (str2[i] == 'u' && str2[i + 1] == 'e' && str2[i + 2] == '"')
			{
				i += 6;
				FoundValue = true;
			}
		}
		
		if (FoundId) it = mapa.find(id);
		if (FoundValue)
		{
			if (str2[str2.size()-1] == '"')
			{
				str2.pop_back();
				str2 += it->second + '"';
			}
			if (str2[str2.size()-1] == ',')
			{
				str2.erase(str2.end() - 2, str2.end());
				str2 += it->second + '"' + ',';
			}
		}
		Out << str2 << '\n';

	}
	return 0;
}
