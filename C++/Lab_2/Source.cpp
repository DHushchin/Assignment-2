#include "Header.h"

vector<string> get_files(string& directory) {
	vector<string> files;
	_finddata_t source;
	string dir;
	cout << "Enter the directory: "; cin >> dir;
	if (dir[dir.size() - 1] != '\\') dir += '\\';
	intptr_t handle = _findfirst((dir + "*.csv").c_str(), &source);
	cout << "Starting these files: " << endl;
	cout << "========================" << endl;
	do {
		string name = source.name;
		if (name != "results.csv") {
			files.push_back(dir + source.name);
			cout << dir + source.name << endl;
		}
	} while (_findnext(handle, &source) == 0);
	directory = dir;
	_findclose(handle);
	return files;
}

// создаёт вектор из пар, где 1 - страна, 2 - голоса за неё
vector<pair<string, vector<int>>> get_data(vector<string> files, int& numberOfCountries) {
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
						numbers.push_back(stoi(currNumber));
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

// создаёт вектор с результатами поинтов, которые получила страна
vector<pair<string, int>> get_results(vector<string> files, int& numberOfCountries) {
	vector<pair<string, int>> results;
	vector<pair<string, vector<int>>> data = get_data(files, numberOfCountries);
	pair<string, int> pair;
	for (size_t i = 0; i < data.size(); i++)
	{
		pair.first = data[i].first;
		pair.second = count(data, i);
		results.push_back(pair);
	}
	return results;
}

// считает поинты, которые получила страна
int count(vector<pair<string, vector<int>>> data, size_t curr) {
	int points = 0;
	for (size_t columns = 0; columns < data[0].second.size(); columns++)
	{
		int bigger = 0;
		for (size_t rows = 0; rows < data.size(); rows++)
		{
			if (rows == curr) {
				continue;
			}
			if (data[curr].second[columns] < data[rows].second[columns]) {
				bigger++;
			}
		}
		if (bigger == 0) {
			points = points + 12;
		}
		else if (bigger == 1) {
			points = points + 10;
		}
		else if (bigger <= 9) {
			points = points + (10 - bigger);
		}
	}
	return points;
}

// выводит в results.csv
void output(vector<pair<string, int>> results, string dir) {
	ofstream output(dir + "results.csv");
	results = sort(results);
	for (size_t i = 0; i < 10; i++)
	{
		output << results[i].first << ", " << results[i].second << endl;
	}
	cout << "========================" << endl;
	cout << "Results.csv was saved in " + dir;
	output.close();
}

// сортирует, чтобы топ-10 был в правильном порядке
vector<pair<string, int>> sort(vector<pair<string, int>> results) {
	pair<string, int> temp;
	for (size_t i = 0; i < results.size() - 1; i++) {
		for (size_t j = 0; j < results.size() - i - 1; j++) {
			if (results[j].second < results[j + 1].second) {
				temp = results[j];
				results[j] = results[j + 1];
				results[j + 1] = temp;
			}
		}
	}
	return results;
}