#pragma once
#include <iostream>
#include <fstream>
#include "Nodes.h"
#include "Rib.h"
using namespace std;

class Deikstra
{
public:
	RibList Ribs;
	void ReadFromFile(string);//read from file
	int Alg(string, string);//algoritmh Deikstri
};