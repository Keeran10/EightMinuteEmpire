#pragma once

class BiddingFacility {

	// Properties
	int *bid;
	public:
		// Constructors & Destructor
		BiddingFacility();
		~BiddingFacility();

		// Getters & Setters
		inline int GetBid() { return *bid; };
		inline void SetBid(int bid) {
			delete this->bid;
			int* a = new int(bid);
			this->bid = a;
		}

		// Functions
		void RandomizeBid();
};