#pragma once
#include <direct.h>
#include <io.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> get_files(string&); // get all files from the directory
vector<pair<string, vector<int>>> get_data(vector<string>, int&); // creates vector [country - votes]
vector<pair<string, int>> get_results(vector<string>); // creates vector [country - points]
int count(vector<pair<string, vector<int>>> data, size_t curr); // counts points
void output(vector<pair<string, int>>, string); // writes results to result_cpp.csv file
vector<pair<string, int>> sort(vector<pair<string, int>>); // sorts TOP-10 in right order
