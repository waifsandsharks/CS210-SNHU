/*
 * Oviparous.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: 1771245_snhu
 */

#include "Oviparous.h"

Oviparous::Oviparous(int t_TrackNum,
		string t_name,
		string t_type,
		string t_subType,
		int t_NumberOfEggs) : Animal(t_TrackNum, t_name, t_type, t_subType, t_NumberOfEggs) {
	this->NumberOfEggs = t_NumberOfEggs;
}

Oviparous::~Oviparous() {
	// Auto-generated destructor stub
}
