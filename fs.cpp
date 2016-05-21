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

#include "fs.h"
#include "helpers.h"

#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

Fs::Fs()
{
	/*
	files = "";
	tots = "";
	useds = "";
	frees = "";
	percus = "";
	mountp = "";
	*/
}

Fs::Fs(const char *name)
{
	vector<string> lines;
	char cmd[] = "df -h ";
	
	strcat(cmd, name);
	
	Helpers h;
	string info = h.readPipe(cmd);
	lines = h.split(info, '\n');
	out = h.split(lines[1], ' ');
	
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