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
#include <map>
#include <regex>

using namespace std;

//--------------------------------> Begin Helpers Definition

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

void Helpers::vClear()
{
	lines.clear();
	info.clear();
}

void Helpers::vClear(vector<string> &v)
{
	v.clear();
}

void Helpers::linesFrom(string file)
{
	vector<string> *output;
	output = &lines;
	ifstream f;
	string line;
	
	//Helpers h;
	if (!(fileExists(file))) sendMessage("ERROR: file doesn't exists or is unreadable");
	
	f.open(file, ios::in);
	while (f.good()) {
		getline(f, line);
		if (line != "") output->push_back(line);
	} f.close();
}

string Helpers::readPipe(const char *cmd)
	FILE *in;
	char buff[512];
	string output = "";
	
	if(!(in = popen(cmd, "r"))) output = "Error: command not found";
	
	while(fgets(buff, sizeof(buff), in) != NULL) {
		string str(buff);
		output += str;
	}
	
	pclose(in);
	
	return output;
}

vector<string> Helpers::split(const string &s, char delim)
{
	vector<string> elems;
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
	vector<string> *v;
	v = &info;
	
	v->push_back(s.arch);
	v->push_back(s.distro);
}

void Helpers::sendMessage(string m)
{
	string *msg;
	msg = &message;
	
	*msg = m;
	
	cout << *msg << endl;
}

string Helpers::escapeStr(string s)
{
	string o;

	for (string::iterator it = s.begin(); it != s.end(); ++it) {
		char c = *it;
		if (c == '{') o += "\\{";
		else if (c == '}') o += "\\}";
		else o += c;
	}

	return o;
}

vector<string> Helpers::mapKeys(map<string,string> m)
{
	vector<string> v;

	for (map<string,string>::iterator it = m.begin(); it != m.end(); ++it) {
		v.push_back(it->first);
	}

	return v;
}

void Helpers::insertData(string in, regex re, map<string,string> m, vector<string> mk)
{
	//string *o = &out;
	smatch s;

	if (regex_search(in, s, re)) {

		string k = escapeStr(s.str());
		regex re_tmp(k);

		for (int i = 0; i < mk.size(); i++) {
			if (s.str() == mk[i]) {
				out = regex_replace(in, re_tmp, m[s.str()]);
				matches(out, re, m, mk);
			} else out = regex_replace(in, re_tmp, "Key not found");
		}
	}
}

//--------------------------------> Begin SystemInfo Definition

SystemInfo::SystemInfo()
{
	getArchitecture();
	getLinuxDistro();
}

SystemInfo::~SystemInfo()
{
}

void SystemInfo::getArchitecture()
{
	Helpers h;
	const char *cmd = "uname -m";
	
	string *o;
	o = &arch;
	
	string s = h.readPipe(cmd);
	s.erase(s.size()-1);
	
	*o = s;
}

void SystemInfo::getLinuxDistro()
{
	ifstream f;
	string line, out, prefix = "NAME=";
	string file = "/etc/os-release";
	
	string *o;
	o = &distro;
	
	Helpers h;
	
	if (!(h.fileExists(file))) *o = "Could not retrive distro.";
	
	f.open(file, ios::in);
	
	while (f.good()) {
		getline(f, line);
		if(line.substr(0, prefix.size()) == prefix) {
			line = line.substr(prefix.size()+1);
			*o = line.erase(line.size()-1);
		} f.close();
	}
}