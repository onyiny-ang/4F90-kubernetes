#ifndef SALMON_H
#define SALMON_H

// Dependencies

#include <stdio.h>
#include <math.h>
#include "Global.h"
#include "MiscFunctions.h"
#include "FlowNetwork.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

class FlowNetwork;              // forward declaration

class Salmon {

	private:
		friend class FlowNetwork;
		int* tabu;              // Tabu list (tour) for this salmon
		int* sortedMemory;      // Memory sorted.
		int currentPointer;     // Points to current location of this salmon in tabu list
		int size;               // Number of vertices
		double pathLength;      // Length of the tour

		

		
	public:
		Salmon(int numPts);
		~Salmon();
		int* memory;            // Salmon's memory of its parents' tour
		bool scanTabu(int n);
		void resetTabu();
		double calcNormalization(FlowNetwork* fnet);
		void setPathLength(double** adjMat);
		double getPathLength();
		void setRandomPath();
		void move(FlowNetwork* fnet);
		void copy(Salmon* source);
		int* copyPath();
		void setPath(int* newPath); // to be removed later
		
		
};

#endif
