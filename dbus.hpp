#ifndef DBUS_H
#define DBUS_H

#include </usr/include/dbus-c++-1/dbus-c++/dbus.h>
#include <iostream>

using namespace DBus;

class DbusHandler
{
public:
	DbusHandler();
	~DbusHandler();
};

DbusHandler::DbusHandler() //Errore nella libreria? provare con dbus-1/dbus.h
{
	Connection *connection;
	Error error;
}

DbusHandler::~DbusHandler()
{
	
}

#endif //DBUS_H