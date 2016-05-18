#include "helpers.h"

#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <dirent.h>

using namespace std;

Helpers::Helpers()
{
}

Helpers::~Helpers()
{
}

bool Helpers::fileExists(string file)
{
	ifstream f;
	f.open(file, ios::in);
	if (f.is_open()) return true; 
	else return false;
}

bool Helpers::dirExists(string dir)
{
	DIR *pd;
	
	pd = opendir(dir.c_str());
	
	if (pd != NULL) { 
		closedir(pd);
		return true;
	}
	else return false;
}

/*array Helpers::lineFrom(string file)  //Deve ritornare un array
{
	Helpers h;
	if not (h.fileExists(file)) return 
	
}*/

 /*
bool Helpers::linesMatch(string regepx, string file)
{
	
}*/

string Helpers::readPipe(const char *cmd)
{
	FILE *in;
	char buff[512];
	string output = "";
	
	if(!(in = popen(cmd, "r"))) output = "Error";
	
	while(fgets(buff, sizeof(buff), in)!=NULL){
		string str(buff);
		output = output + str;
	}
	
	pclose(in);
	
	return output;
}

vector<string> Helpers::split(const string &s, char delim, vector<string> elems)
{
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		if (item != "") {
			elems.push_back(item);
		}
	}
	return elems;
}
