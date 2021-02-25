#include <direct.h>
#include <io.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> get_files(const std::string&);

using namespace std;

int main() {
	vector<pair<string, vector<int>>> data;
	setlocale(LC_ALL, "russian");
	string dir;
	vector<string> files = get_files("Enter the path: "); 
	return 0;
}

string get_dir(const string& dir) {
	string str;
	cout << dir << ": ";
	cin >> str;
	return str;
}

vector<string> get_files(const string& dir) {
	vector<string> files;
	_finddata_t source;
	string path = get_dir(dir);
	if (path[path.size() - 1] != '\\') path += '\\';
	intptr_t handle = _findfirst((path + "*.csv").c_str(), &source);
	do {
		if (source.name != "results.csv") files.push_back(path + source.name);
		cout << path + source.name << endl;
	} while (_findnext(handle, &source) == 0);
	_findclose(handle);
	return files;
}
