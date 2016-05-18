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
		}
	}
	
	f.close();
	
	path = pd->mnDir + "Themes/" + name;
}

Theme::~Theme()
{
}