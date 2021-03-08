
#include "Header.h"


int main() {
	vector<pair<string, int>> results;
	string dir;
	setlocale(LC_ALL, " ");
	int numberOfCountries = 0;
	vector<string> files = get_files(dir);
	results = get_results(files, numberOfCountries);
	output(results, dir);
	system("pause>>void");
	return 0;
}

