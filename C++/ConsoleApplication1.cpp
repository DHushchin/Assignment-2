#include <direct.h>
#include <io.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> get_files();
vector<pair<string, vector<int>>> get_data(vector<string>, int&);

int main() {
	vector<pair<string, vector<int>>> data;
	setlocale(LC_ALL, " ");
	int numberOfCountries = 0;
	vector<string> files = get_files();
	data = get_data(files, numberOfCountries);
	system("pause>>void");
	return 0;
}

vector<string> get_files() {
	vector<string> files;
	_finddata_t source;
	string dir;
	cout << "Enter the directory: "; cin >> dir;
	if (dir[dir.size() - 1] != '\\') dir += '\\';
	intptr_t handle = _findfirst((dir + "*.csv").c_str(), &source);
	do {
		if (source.name != "results.csv") files.push_back(dir + source.name);
		cout << dir + source.name << endl;
	} while (_findnext(handle, &source) == 0);
	_findclose(handle);
	return files;
}

vector<pair<string, vector<int>>> get_data(vector<string> files, int& numberOfCountries){
	vector<pair<string, vector<int>>> countries;
	string str;
	string currNumber;
	pair<string, vector<int>> pair;
	for (size_t i = 0; i < files.size(); i++)
	{
		ifstream currFile(files[i]);
		while (!currFile.eof()) {
			getline(currFile, str);
			vector<int> numbers;
			string country;
			if (!isdigit(str[0])) {
				country = str.substr(0, str.find(','));
				str.erase(0, str.find(',') + 1);
				while (str.size() != 0)
				{
					if (str.find(',') != str.npos) {
						currNumber = str.substr(0, str.find(','));
						str.erase(0, str.find(',')+1);
						numbers.push_back(stoi(currNumber));
					}
					else {
						str.clear();
					}
				}
				pair.first = country;
				pair.second = numbers;
				countries.push_back(pair);
			}
			else {
				numberOfCountries = numberOfCountries + stoi(str);
			}
		}
		currFile.close();
	}
	return countries;
}

