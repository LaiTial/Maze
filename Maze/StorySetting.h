#pragma once
#include<iostream>
#include<fstream>
#include"string"
using namespace std;

class StorySetting
{
private:
	string strReplace = "ABC";
	string name;
	string strTemp;
	string strNew;
	int height;

public:
	void getName();
	void story_name_set(string filename, string newfilename);
	void read_story(string filename);
};

