#pragma once

class BiddingFacility {
	int bid;
	public:
		BiddingFacility();
		~BiddingFacility();
		int GetBid() { return bid; };
		void SetBid(int bid) { this->bid = bid; }
		void RandomizeBid();
};