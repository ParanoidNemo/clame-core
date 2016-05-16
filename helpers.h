#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Helpers
{
public:
	Helpers();
	~Helpers();
	
	bool fileExists(string);
	vector<string> split(const string &, char, vector<string>);
	string readPipe(const char *);
};

#endif //HELPERS_H