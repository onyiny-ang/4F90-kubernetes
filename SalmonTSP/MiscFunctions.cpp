#include "MiscFunctions.h"


// This function returns a random integer with a high value of high
// and a low value of low.

int randomInt(int low, int high){

	int random;

	random = rand()%((high-low)+1);
	random = random + low;
	return random;

} // end of randomInt()



// This function returns a random double between 0 and 1.

double randomDbl(){

	return (double)rand()/(double)RAND_MAX;

} // end of randomDbl()



// This method performs a partial sort of the salmon array based on path length.

void sort(Salmon** salmonArray){

	Salmon* temp;
	double bestPath;
	int bestIndex;

	for(int i=0;i<SURVIVAL;i++){
		bestPath = BIG_NUMBER;
		for(int j=i;j<POPULATION;j++){
			if(salmonArray[j]->getPathLength() < bestPath){
				bestPath = salmonArray[j]->getPathLength();
				bestIndex = j;
			}
		}
		temp = salmonArray[i];
		salmonArray[i] = salmonArray[bestIndex];
		salmonArray[bestIndex] = temp;
	}
} // end of sort()



// This method produces the children of the best salmon. This is done by
// simply copying the contents (paths and memories) of the most fit salmon
// into the other salmon. This avoids deleting and re-creation of salmon
// every generation. Note, salmonArray has been partially sorted. The most fit
// are salmonArray[0] to salmonArray[SURVIVAL-1].


void produceChildren(Salmon** salmonArray){

	int loop = POPULATION/SURVIVAL;  
	int index;

	sort(salmonArray);

	for(int i=1;i<loop;i++){
		for(int j=0;j<SURVIVAL;j++){
			index = i*SURVIVAL + j;
			salmonArray[index]->copy(salmonArray[j]);
		}
	}
}


// This method saves the elite salmon by copying its data into
// random salmon in the salmon array.

void saveElite(Salmon* elite, Salmon** salmonArray){

	int random;

	for(int j=0;j<ELITE;j++){
		random = randomInt(0,POPULATION-1);
		salmonArray[random]->copy(elite);
	}

} // end of saveElite()




// This method gets the elite salmon by comparing the current elite
// to the best salmon of this generation. Note, salmonArray has been
// sorted for first SURVIVAL salmon. The most fit is salmonArray[0];

bool getElite(Salmon* elite, Salmon** salmonArray){

	if(salmonArray[0]->getPathLength()< elite->getPathLength()){
		elite->copy(salmonArray[0]);
		return true;
	}

	return false;

} // end of getElite()




// This method resets the elite salmon at the end of an epoch.

void resetElite(Salmon* elite, double** adjMatrix){

	elite->setRandomPath();
	elite->setPathLength(adjMatrix);

} // end of resetElite()



