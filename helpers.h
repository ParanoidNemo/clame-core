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


/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * SystemInfo										   *
 * 													   *
 * class used to retrive informations about the system *
 * like distro name, architecture, kernel version etc. *
 * All the infos are gathered into the costructor and  *
 * could be retrived using the function gatherSysInfo  *
 * located under the friend class Helpers			   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class SystemInfo
{
	friend class Helpers;
	
public:
	SystemInfo();
	~SystemInfo();
	
private:
	void getArchitecture();		// Set arch variable with the system architecture
	void getLinuxDistro();		// Set distro variable with the distro name
	
	string arch;
	string distro;
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Helpers											   *
 * 													   *
 * class containing simple methods used more times	   *
 * into the main program. All methods and var are set  *
 * to public for better usability					   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class Helpers
{
public:
	Helpers();
	~Helpers();
	
	bool fileExists(string);										// Check if a given file exists
	bool dirExists(string);											// Check if a given dir exists
	vector<string> split(const string &, char, vector<string>);		// Split a given string by delimitator
	void linesFrom(string);											// Retrive all lines from a file and store
																	// it into lines tmp var
	string readPipe(const char *);									// Return output from a unix command
	void gatherSysInfo(SystemInfo);									// Retrive info from SystemInfo costructor
																	// and store it into info tmp var
	
	void sendMessage(string);										// Store a string into message tmp var and
																	// print it into terminal -- Right now used
																	// expecially for debug porpouse
	
	vector<string> lines;											// tmp var for storing linesFrom output
	vector<string> info;											// tmp var for storing gatherSysInfo output
	string message;													// tmp var for storing sendMessage input
};


#endif //HELPERS_H