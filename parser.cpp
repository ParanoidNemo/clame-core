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

#include "parser.h"

#include "helpers.h"

#include <string>
#include <map>
#include <ifstream>
#include <iostream>

using namespace std;

Parser::Parser(string file)
{
	ifstream f;
	string line;
	
	Helpers h;
	if (!(h.fileExists(file)) cout << "ERROR: File not found or unreadable" << endl;
	
	f.open(file);
	while (f.good()) {
		getline(f, line);
        if (string::iterator line[0] == '[') {
            section = line.substr(line.begin()+1, line.size()-1);
        } else lines = h.split(line, '=');
        
        if (section == "main") {
            if (lines.size() > 1) main.emplace(lines[0], lines[1]);
            h.vClear(lines);
        } else if (section == "updater") {
            if (lines.size() > 1) updater.emplace(lines[0], lines[1]);
            h.vClear(lines);
        }
	}
}

/*
 * vector = h.split(string);
 * if (vector.size() > 1) map.emplace(vector[0], vector[1]);
 */