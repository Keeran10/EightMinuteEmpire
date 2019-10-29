#pragma once

class BiddingFacility {

	// Properties
	private:
		int bid;
	public:
		// Constructors & Destructor
		BiddingFacility();
		~BiddingFacility();

		// Getters & Setters
		inline int GetBid() { return bid; };
		inline void SetBid(int bid) {
			this->bid = bid;
		}

		// Functions
		void RandomizeBid(int coins);
};