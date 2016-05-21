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

#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class SystemInfo
{
	friend class Helpers;
	
public:
	SystemInfo();
	~SystemInfo();
	
private:
	void getArchitecture();
	void getLinuxDistro();
	
	string arch;
	string distro;
};

class Helpers
{
public:
	Helpers();
	~Helpers();
	
	bool fileExists(string);
	bool dirExists(string);
	vector<string> split(const string &, char, vector<string>);
	void linesFrom(string);
	string readPipe(const char *);
	void gatherSysInfo(SystemInfo);
	
	void sendMessage(string);
	
	vector<string> lines;
	vector<string> info;
	string message;
};


#endif //HELPERS_H