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

#ifndef UPDATER_H
#define UPDATER_H

#include <string>
#include <map>

using namespace std;

class Updater
{
public:
	Updater();
	~Updater();
	
	void checkUpdates(string *);
	
	string updates;
	
private:
	map<string,string> packageManagerList = {{"Arch Linux", "pacman"}, 
											 {"Ubuntu", "aptitude"}, 
											 {"Fedora", "dnf"}};
											 
	string packageManager;
};

#endif //UPDATER_H