#include "helpers.h"
#include "fs.h"

#include <iostream>

int main(int argc, char **argv)
{
	Fs w("/");
	printInfo(w);
	return 0;
}

void printInfo(Fs fs)
{
	Fs *f;
	f = &fs;
	
	cout << f->mountp << endl << f->frees << endl;
}