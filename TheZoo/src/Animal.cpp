/*
 * Animal.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: Ethan Daugherty 1771245_snhu
 */

#include "Animal.h"

Animal::Animal(int t_TrackNum, string t_name, string t_type, string t_subType, int additionalData) {
	this->TrackNum = t_TrackNum;
	this->name = t_name;
	this->type = t_type;
	this->subType = t_subType;
	this->additionalData = additionalData;
}

Animal::~Animal() {
	// Auto-generated destructor stub
}
