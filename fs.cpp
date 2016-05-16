#include "fs.h"
#include "helpers.h"

#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

Fs::Fs()
{
	files = "";
	tots = "";
	useds = "";
	frees = "";
	percus = "";
	mountp = "";
}

Fs::Fs(const char *name)
{
	char cmd[] = "df -h ";
	
	strcat(cmd, name);
	
	Helpers h;
	string info = h.readPipe(cmd);
	lines = h.split(info, '\n', item);
	out = h.split(lines[1], ' ', item);
	
	files = out[0];
	tots = out[1];
	useds = out[2];
	frees = out[3];
	percus = out[4];
	mountp = out[5];
}

Fs::~Fs()
{
	
}