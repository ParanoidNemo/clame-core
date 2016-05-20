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

#include "updater.h"

#include "helpers.h"

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

Updater::Updater()
{
	vector<string> *i;
	
	SystemInfo s;
	Helpers h;
	
	h.gatherSysInfo(s, i);
	
	packageManager = packageManagerList[h.info[1]];
}

Updater::~Updater()
{
}

void Updater::checkUpdates(string *up)
{
	up = &updates;
	string *msg;
	
	Helpers h;
	h.message = "Checking Updates...";
	
	if (packageManager == "pacman") {
		h.sendMessage(msg);
		*up = h.readPipe("checkupdates | wc -l");
	} else if (packageManager == "aptitude") {
		*up = "";
	} else if (packageManager == "dnf") {
		*up = "";
	} else cout << "Package Manager not found";
}