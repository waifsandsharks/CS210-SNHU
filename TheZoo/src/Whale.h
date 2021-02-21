/*
 * Whale.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1771245_snhu
 */
#ifndef WHALE_H_
#define WHALE_H_

#include "Mammal.h"

class Whale : public Mammal {
public:
	Whale(int t_TrackNum, string t_name, string t_type, string t_subType, int t_Nurse);
	virtual ~Whale();
};

#endif /* WHALE_H_ */
