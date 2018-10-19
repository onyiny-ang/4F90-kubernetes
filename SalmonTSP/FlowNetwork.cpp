#include "FlowNetwork.h"


// constructor
FlowNetwork::FlowNetwork(double** adjMatrix, int numPts){
	this->size = numPts;
	this->totalFlow = new double*[this->size];
	this->averageFlow = new double*[this->size];
	this->totalSalmon = new int*[this->size];
	this->adjacency = new double*[this->size];

	for(int i=0;i<this->size;i++){
		this->totalFlow[i] = new double[this->size];
		this->averageFlow[i] = new double[this->size];
		this->totalSalmon[i] = new int[this->size];
		this->adjacency[i] = new double[this->size];
	}
	for(int i=0;i<this->size;i++){
		for(int j=0;j<this->size;j++){
			this->adjacency[i][j] = adjMatrix[i][j];
		}
	}
	this->initializeFlow();

} // end constructor()


// destructor
FlowNetwork::~FlowNetwork(){

	for(int i=0;i<this->size;i++){
		delete[] this->totalFlow[i];
		delete[] this->averageFlow[i];
		delete[] this->totalSalmon[i];
	}

	delete[] this->averageFlow;
	delete[] this->totalFlow;
	delete[] this->totalSalmon;

} // end destructor()



// This function initializes the flow in all edges to a value inversely
// proportional to the length of the edge.

void FlowNetwork::initializeFlow(){

	for(int i=0;i<this->size;i++){
		for(int j=0;j<this->size;j++){
			if(i!=j){
				this->totalFlow[i][j] = BEST_KNOWN/(BEST_KNOWN + (this->adjacency[i][j]*(double)this->size));
				this->totalSalmon[i][j] = 1;
				this->averageFlow[i][j] = this->totalFlow[i][j];
			}
		}
	}

} // end of initializeFlow()



// This function returns the average flow in the edge from vertex i to vertex j.

double FlowNetwork::getAverageFlow(int i, int j){

	return this->averageFlow[i][j];

} // end getAverageFlow()



// This method updates the flows

void FlowNetwork::updateFlows(Salmon** salmonArray){

	double flow;

	for(int i=0;i<POPULATION;i++){
		flow = BEST_KNOWN/salmonArray[i]->getPathLength();
		for(int j=0;j<this->size-1;j++){
			this->totalFlow[salmonArray[i]->tabu[j]][salmonArray[i]->tabu[j+1]] += flow;
			this->totalFlow[salmonArray[i]->tabu[j+1]][salmonArray[i]->tabu[j]] += flow; // symmetrical
			this->totalSalmon[salmonArray[i]->tabu[j]][salmonArray[i]->tabu[j+1]] += 1;
			this->totalSalmon[salmonArray[i]->tabu[j+1]][salmonArray[i]->tabu[j]] += 1; // symmetrical
		}
		// add in the edge from last vertex back to the first
		this->totalFlow[salmonArray[i]->tabu[this->size-1]][salmonArray[i]->tabu[0]] += flow;
		this->totalFlow[salmonArray[i]->tabu[0]][salmonArray[i]->tabu[this->size-1]] += flow;
		this->totalSalmon[salmonArray[i]->tabu[this->size-1]][salmonArray[i]->tabu[0]] += 1;
		this->totalSalmon[salmonArray[i]->tabu[0]][salmonArray[i]->tabu[this->size-1]] += 1;
	}

	for(int i=0;i<this->size;i++){
		for(int j=0;j<this->size;j++){
			if(i!=j){
				this->averageFlow[i][j] = this->totalFlow[i][j];
//				this->averageFlow[i][j] = this->totalFlow[i][j]
//			                            /(double)this->totalSalmon[i][j];
			}
		}
	}
} // end of updateFlows()



