#ifndef FS_H
#define FS_H

#include <string>
#include <vector>

using namespace std;

class Fs
{
	
public:
	Fs();
	Fs(const char *);
	~Fs();
	
	friend void printInfo(Fs);
	
private:
	string mountp, frees, tots, useds, percus, files;
	vector<string> lines, out, item;
};

#endif //FS_H