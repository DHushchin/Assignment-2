#include "Parsing.h"

int main() {
	vector<pair<string, int>> results;
	string dir;
	setlocale(LC_ALL, " ");
	vector<string> files = get_files(dir);
	results = get_results(files);
	output(results, dir);
	system("pause>>void");
	return 0;
}

