#include <direct.h>
#include <io.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#pragma once
vector<string> get_files(string&);
vector<pair<string, vector<int>>> get_data(vector<string>, int&);
vector<pair<string, int>> get_results(vector<string>, int&);
int count(vector<pair<string, vector<int>>> data, size_t curr);
void output(vector<pair<string, int>>, string);
vector<pair<string, int>> sort(vector<pair<string, int>>);