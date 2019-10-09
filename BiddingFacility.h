#pragma once

class BiddingFacility {
	int bid;
	public:
		BiddingFacility();
		~BiddingFacility();

		inline int GetBid() { return bid; };
		inline void SetBid(int bid) { this->bid = bid; }

		void RandomizeBid();
};