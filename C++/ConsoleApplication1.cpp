#include <direct.h>
#include <io.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> get_files(string&); // gets list of files from the directory
vector<pair<string, int>> get_results(vector<string>, int&); // parses files
vector<pair<string, vector<int>>> get_data(vector<string>, int&); // forms vector [country - votes]
vector<pair<string, vector<int>>> sort_col(vector<pair<string, vector<int>>> data); // sorts votes in columns
void get_points(vector<pair<string, vector<int>>>&); // converts votes into points
int sum_points(vector<int>); // sums points in a row
void save_res(vector<pair<string, int>>, string); // saves result to results.csv


int main() {
	vector<pair<string, int>> results;
	string dir;
	setlocale(LC_ALL, " ");
	int numberOfCountries = 0;
	vector<string> files = get_files(dir);
	results = get_results(files, numberOfCountries);
	save_res(results, dir);
	system("pause >> void");
	return 0;
}

vector<string> get_files(string &dir) {
	vector<string> files;
	_finddata_t source;
	cout << "Enter the directory: "; cin >> dir;
	if (dir[dir.size() - 1] != '\\') dir += '\\';
	intptr_t handle = _findfirst((dir + "*.csv").c_str(), &source);
	cout << "List of files: " << endl;
	cout << "========================" << endl;
	do {
		string name = source.name;
		if (name.find("result") == string::npos) { // ignore result.csv files
			files.push_back(dir + source.name);
			cout << dir + source.name << endl;
		}
	} while (_findnext(handle, &source) == 0);
	_findclose(handle);
	return files;
}


vector<pair<string, vector<int>>> get_data(vector<string> files, int& numberOfCountries){
	vector<pair<string, vector<int>>> countries;
	for (size_t i = 0; i < files.size(); i++)
	{
		string str;
		string currNumber;
		pair<string, vector<int>> pair;
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
						str.erase(0, str.find(',') + 1);
						numbers.push_back(stoi(currNumber));
					}
					else {
						currNumber = str.substr(0, str.length());
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


vector<pair<string, int>> get_results(vector<string> files, int& numberOfCountries) {
	vector<pair<string, int>> results;
	vector<pair<string, vector<int>>> data;
	data = get_data(files, numberOfCountries);
	get_points(data);
	pair<string, int> pair;
	for (size_t i = 0; i < data.size(); i++)
	{
		pair.first = data[i].first;
		pair.second = sum_points(data[i].second);
		results.push_back(pair);
		cout << results[i].first << '\t' << results[i].second << endl;
	}
	return results;
}


void save_res(vector<pair<string, int>> results, string dir) {
	ofstream output(dir + "results_cpp.csv");
	for (size_t i = 0; i < 10; i++)
	{
		output << results[i].first << ", " << results[i].second << endl;
	}
	cout << "========================" << endl;
	cout << "Results.csv was saved in " + dir;
	output.close();
}


int sum_points(vector<int> votes) {
	int points = 0;
	for (size_t i = 0; i < votes.size(); i++) points += votes[i];
	return points;
}


void get_points(vector<pair<string, vector<int>>>& data) {
	vector<pair<string, vector<int>>> sorted_data = sort_col(data);
	for (int col = 0; col < data[0].second.size(); col++) {
		for (int row = 0; row < data.size(); row++) {
			for (int i = 0; i < 10; i++) {
				if (data[row].second[col] == sorted_data[i].second[col] && i == 0) { data[row].second[col] = 12; }
				else if (data[row].second[col] == sorted_data[i].second[col] && i == 1) { data[row].second[col] = 10; }
				else if (data[row].second[col] == sorted_data[i].second[col] && i > 1 && i < 10) { data[row].second[col] = 10 - i; }
				else data[row].second[col] = 0;
			}
		}
	}
}


vector<pair<string, vector<int>>> sort_col(vector<pair<string, vector<int>>> data) {
	for (int col = 0; col < data[0].second.size(); col++) {
		for (int row = 0; row < data.size() - 1; row++) {
			if (data[row].second[col] > data[row + 1].second[col]) {
				swap(data[row].first, data[row + 1].first);
				swap(data[row].second[col], data[row + 1].second[col]);
			}
			cout << data[row].first << '\t' << data[row].second[col] << endl;
		}
		cout << endl;
	}
	return data;
}





