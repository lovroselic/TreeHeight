// https://www.codeabbey.com/index/task_view/tree-height-measurement
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>
#include <cmath>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"
#define PI 3.14159265

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int TreeHeight(int D, double B);

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "TreeHeight v" << VERSION << "!\n\n";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> raw_data = loadData(path);

	vector<int> solution;

	for (int i = 1; i < raw_data.size(); i++) {
		vector<string> line = splitString(raw_data[i], " ");
		int D = stoi(line[0]);
		double B = stod(line[1]);
		int H = TreeHeight(D,B);
		solution.push_back(H);
		cout << raw_data[i] << " : " << H << endl;
	}
	cout << "\nSolution: " << joinVector(solution, " ") << endl;;

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
}
int TreeHeight(int D, double B) {
	double A = B - 90.0;
	double H = tan(A * PI/180) * D;
	return round(H);
};
