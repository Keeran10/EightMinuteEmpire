#include "BiddingFacility.h"
#include <stdlib.h>
#include <time.h>

// Default Constructor
BiddingFacility::BiddingFacility() : bid(0)
{
	// Generate random seed
	srand(time(NULL));
}

// Default Destructor
BiddingFacility::~BiddingFacility()
{
}

// Generate a random bid and set it to variable
void BiddingFacility::RandomizeBid()
{
	bid = rand() % 11;
}
