#pragma once
#ifndef _LIBRARY_ARCH_H_
#define _LIBRARY_ARCH_H_
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <map>
#include <iterator>
#include <string>
#include <sstream>
#include <fstream>
#include <cstddef>

using namespace std;
class fileSystemParser
{
public:
	fileSystemParser()
	{
	}

	virtual ~fileSystemParser()
	{
	}

	virtual void listDir(char *) = 0;
	virtual void output() = 0;
};

class Result
{
	map<string, string> ds;
	map<string, string> finalResult;
	map<string, string>::iterator ir1, ir2;
	string fileLocation;
	ofstream fileHandler;
public:
	Result()
	{
	}
	Result(const char *str)
	{
		string t = "\\result.txt";
		fileLocation = str + t;
		fileHandler.open(fileLocation);
	}
	~Result()
	{
		fileHandler.close();
	}

	void prepareResult();
	void addToMap(char *filePath, const char *inputString);
};

class Windows : virtual public fileSystemParser
{
	const char *inputString;
	Result rs;
public:
	Windows(char *str):inputString(str), rs(inputString)
	{
	}

	~Windows()
	{
	}

	void listDir(char * dirn);
	void output();
};

#endif






