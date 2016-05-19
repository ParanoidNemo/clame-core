/**************************************************************************
*   Copyright (C) 2016 by Andrea Calzavacca                               *
*   paranoid.nemo@gmail.com                                               *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/

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
	if (f.is_open()) {
		f.close();
		return true;
	}
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

vector<string> Helpers::linesFrom(string file)
{
	vector<string> output;
	ifstream f;
	string line;
	
	Helpers h;
	if (!(h.fileExists(file))) return output;
	
	f.open(file, ios::in);
	while (f.good()) {
		getline(f, line);
		if (line != "") output.push_back(line);
	} f.close();
	
	return output;
}

string Helpers::readPipe(const char *cmd)	// Need to modify to use a bigger buffer without using char
{
	FILE *in;
	char buff[1024];
	string output = "";
	
	if(!(in = popen(cmd, "r"))) output = "Error: command not found";
	
	while(fgets(buff, sizeof(buff), in) != NULL) {
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

void Helpers::gatherSysInfo(SystemInfo s)
{
	SystemInfo *o;
	
	o = &s;
	
	cout << "Architecture: " << o->arch;
	cout << "Distro: " << o->distro << endl;
}

SystemInfo::SystemInfo()
{
	arch = getArchitecture();
	distro = getLinuxDistro();
}

SystemInfo::~SystemInfo()
{
}

string SystemInfo::getArchitecture()
{
	Helpers h;
	const char *cmd = "uname -m";
	
	string out = h.readPipe(cmd);
	
	return out;
}

string SystemInfo::getLinuxDistro()
{
	ifstream f;
	string line, out, prefix = "NAME=";
	string file = "/etc/os-release";
	
	Helpers h;
	
	if (!(h.fileExists(file))) return out = "Could not define distro.";
	
	f.open(file, ios::in);
	
	while (f.good()) {
		getline(f, line);
		if(line.substr(0, prefix.size()) == prefix) {
			line = line.substr(prefix.size()+1);
			out = line.erase(line.size()-1);
		} f.close();
	}
	
	return out;
}