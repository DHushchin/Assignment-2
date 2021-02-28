#include <direct.h>
#include <io.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> get_files();
vector<string> get_data(vector<string>);

int main() {
	vector<pair<string, vector<int>>> data;
	setlocale(LC_ALL, " ");
	vector<string> files = get_files();
	vector<string> data = get_data(files);
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

vector<string> get_data(vector<string> files){
	vector<string> countries;
	string str;
	for (size_t i = 0; i < files.size(); i++)
	{
		ifstream currFile(files[i]);
		while (!currFile.eof()) {
			getline(currFile, str);
			if (!isdigit(str[0])) {
				countries.push_back(str);
			}
		}
	}
	return countries;
}

