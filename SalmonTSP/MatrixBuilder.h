#ifndef MATRIXBUILDER_H
#define MATRIXBUILDER_H

// Dependencies

#include <stdio.h>
#include <math.h>
#include "Global.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


/* */

class MatrixBuilder {

	private:
		

		
	public:
		MatrixBuilder();
		~MatrixBuilder();
		double** buildAdjacencyMatrix(std::ifstream* inFile, int& size);
		
};

#endif