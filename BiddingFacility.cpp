#include "BiddingFacility.h"
#include <stdlib.h>
#include <time.h>

BiddingFacility::BiddingFacility() : bid(0)
{
	srand(time(NULL));
}

BiddingFacility::~BiddingFacility()
{
}

void BiddingFacility::RandomizeBid()
{
	bid = rand() % 11;
}
