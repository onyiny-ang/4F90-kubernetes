#include "MatrixBuilder.h"
#include "FlowNetwork.h"
#include "Salmon.h"
#include "MiscFunctions.h"
#include <sys/times.h>
#include <sys/param.h>
#include <sys/types.h>

using namespace std;

/* This program is the salmon algorithm for the TSP. Input data must be in the
   form of a text file with the first line being the number of vertices N, and
   the next N lines being the vertex number, x coordinate, and y coordinate
   of each vertex. Berlin52 is normally this format for example. tHis program
   has been set up to run on the cluster. Check Global.h for user defined
   parameter values. */


int main(){

    struct tms ticksBegin, ticksEnd; // for program execution timing
    long long beginTime, endTime; // for program timing
    double totalTime;             // Program run time (seconds).
    long long seed;               // seed for random number generator
    long long sTime;              // for random number seed
    int seedMultiplier;      // For getting different seeds in each process
    int numVertex;           // Number of cities
    double** adjMatrix;      // Adjacency matrix of distances
    int* bestPath;           // Best ever path
    double bestLength;       // Best ever path length
    int bestGen;             // Generation when best path occurred
    MatrixBuilder* mBuilder; // Creates the adjacency matrix
    FlowNetwork* fNetwork;   // Manages the flows
    Salmon** theSalmon;      // Array of Salmon objects
    Salmon* eliteSalmon;     // The elite salmon
//  int testPath[52] = {0,48,31,44,18,40,7,8,9,42,32,50,10,51,13,12,46,25,26,27,11,24,3,5,14,4,
//  23,47,37,36,39,38,35,34,33,43,45,15,28,49,19,22,29,1,6,41,20,16,2,17,30,21};

    ifstream inFile(SEED_FILE_NAME, ios::in);    // open the file with the seed multiplier
    inFile >> seedMultiplier;
    inFile.close();
    //Start timing

    beginTime = times(&ticksBegin);
    sTime = time(NULL);
    seed = sTime*seedMultiplier + seedMultiplier;

    srand(seed);  // Can't seed with time(NULL) since this only gives
                  // time to the nearest second. Different processes
                  // get same seed and same results.

    ifstream inFile2(IN_FILE_NAME, ios::in); // open the TSP data file
    if(! inFile2) std:: cout << "Input data file failed to open\n" << std::flush;
    mBuilder = new MatrixBuilder();
    adjMatrix = mBuilder->buildAdjacencyMatrix(&inFile2,numVertex);
    inFile2.close();

    fNetwork = new FlowNetwork(adjMatrix,numVertex);
    bestPath = new int[numVertex];

    theSalmon = new Salmon*[POPULATION];
    for(int i=0;i<POPULATION;i++) theSalmon[i] = new Salmon(numVertex);

    eliteSalmon = new Salmon(numVertex);
    bestLength = BIG_NUMBER;

    for(int m=0;m<RESTARTS;m++){
	fNetwork->initializeFlow();
	for(int n=0;n<POPULATION;n++) theSalmon[n]->setRandomPath();
	resetElite(eliteSalmon, adjMatrix);

	//Run the salmon algorithm

	for(int i=0;i<GENERATIONS;i++){
            for(int j=0;j<POPULATION;j++) theSalmon[j]->resetTabu();
            for(int j=0;j<POPULATION;j++){
                for(int k=0;k<numVertex-1;k++){
                    theSalmon[j]->move(fNetwork);
		}
            }

            for(int j=0;j<POPULATION;j++) theSalmon[j]->setPathLength(adjMatrix);

            /* Note. Producing children before updating flows effectively counts
            the flows of only the SURVIVAL number of best salmon, since these
            are the only salmon left after produce children. This eliminates
            diversity and causes mediocre results. We update flows first, then
            produce children. */

            fNetwork->updateFlows(theSalmon);
            produceChildren(theSalmon);

            cout << "The best path generation " << i << " is " << theSalmon[0]->getPathLength() << "\n";

            if(theSalmon[0]->getPathLength() < bestLength){
		bestLength = theSalmon[0]->getPathLength();
		bestGen = i;
		if(bestPath != NULL) delete[] bestPath;
                bestPath = theSalmon[0]->copyPath();
            }


            if(ELITE == 'Y'){
		if(!getElite(eliteSalmon, theSalmon)) saveElite(eliteSalmon, theSalmon);
            }


            if (bestLength <= (BEST_KNOWN + SMALL_NUMBER)) break;

	}

    }

	// Stop timing

    endTime = times(&ticksEnd);
    totalTime = ((double)(endTime - beginTime))/HZ;

    // Open the output file for writing result

    ofstream outFile(OUT_FILE_NAME, ios::out);     // output file stream

    outFile << "The length of the best path is " << bestLength << "\n";
    outFile << "It occurred first in generation " << bestGen << "\n";
    outFile << "This program took " << totalTime << " seconds to complete.\n\n";
    outFile << "The best path is ";
    for(int i=0;i<numVertex;i++) outFile << bestPath[i] << " ";

    outFile.close();

    delete[] theSalmon;
    delete[] bestPath;
    delete mBuilder;
    delete fNetwork;
    delete eliteSalmon;

    return 0;

}  // end of main()

