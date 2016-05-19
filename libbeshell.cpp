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

#ifdef _DEBUG
#define DBOUT cout
#else
#define DBOUT 0 && cout
#endif

#include "libbeshell.h"
#include "helpers.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Default::Default()
{
	stringstream ss;
	string dir = home + "/.kde4/share/config";
	Helpers h;
	
	bool check = h.dirExists(dir);
	
	if (!check) ss << home << "/.kde/share/config/";
	else ss << home << "/.kde4/share/config/";
	cfgDir = ss.str();
	
	ss << "be.shell";
	mnFile = ss.str(); ss.str(string());
	
	ss << home << "/.kde4/share/apps/be.shell/";
	mnDir = ss.str();
}

Default::~Default()
{
}

Theme::Theme()
{
	Default d;
	Default *pd;
	pd = &d;
	ifstream f;
	f.open(pd->mnFile, ios::in);
	
	string line, prefix = "Theme=";
	
	while (f.good()) {
		getline(f, line);
		if(line.substr(0, prefix.size()) == prefix) {
			name = line.substr(prefix.size());
		} f.close();
	}
	
	f.close();
	
	path = pd->mnDir + "Themes/" + name;
}

Theme::~Theme()
{
}