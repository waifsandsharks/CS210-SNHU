/*
 * SeaLion.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1771245_snhu
 */
#ifndef SEALION_H_
#define SEALION_H_

#include "Mammal.h"

class SeaLion : public Mammal {
public:
	SeaLion(int t_TrackNum, string t_name, string t_type, string t_subType, int t_Nurse);
	virtual ~SeaLion();
};

#endif /* SEALION_H_ */
