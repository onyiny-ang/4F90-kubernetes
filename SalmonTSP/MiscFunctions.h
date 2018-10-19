#ifndef MISCFUNCTIONS_H
#define MISCFUNCTIONS_H

// Dependencies

#include <stdio.h>
#include <math.h>
#include "Global.h"
#include "Salmon.h"
#include <iostream>

class Salmon;          // forward declaration

// This file contains miscellaneous functions 


	int randomInt(int low, int high);
	double randomDbl();
	void sort(Salmon** salmonArray);
	void produceChildren(Salmon** salmonArray);
	void saveElite(Salmon* elite, Salmon** salmonArray);
	bool getElite(Salmon* elite, Salmon** salmonArray);
	void resetElite(Salmon* elite, double** adjMatrix);



#endif