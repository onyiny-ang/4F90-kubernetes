#ifndef FLOWNETWORK_H
#define FLOWNETWORK_H

// Dependencies

 
#include <stdio.h>
#include <math.h>
#include "Global.h"
#include "Salmon.h"
#include "MiscFunctions.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


class Salmon;                    // forward declaration

class FlowNetwork {

	private:
		double** totalFlow;      // Total Flow in each edge
		double** averageFlow;    // Average Flow in each edge
		int** totalSalmon;       // Number of salmon that have used
		                         // each edge.
		int size;                // Number of vertices
		double** adjacency;      // A copy of the adjacency matrix
		

		
	public:
		FlowNetwork(double** adjMatrix, int numPts);
		~FlowNetwork();
		double getAverageFlow(int i, int j);
		void updateFlows(Salmon** salmonArray);
		void initializeFlow();   // Initialize flow values

				
};

#endif
