#ifndef LIBBESHELL_H
#define LIBBESHELL_H

#include <iostream>
#include <stdlib.h>
using namespace std;

class Default
{
	friend class Theme;
public:
	Default();
	~Default();
private:
	const string home = getenv("HOME");
	string cfgDir;
	string mnFile;
	string mnDir;
};

class Theme
{
public:
	Theme();
	~Theme();
	string path;
private:
	string name;
};

#endif //DEFAULT_H