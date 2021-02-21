/*
 * Crocodile.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1771245_snhu
 */

#ifndef CROCODILE_H_
#define CROCODILE_H_

#include "Oviparous.h"

class Crocodile : public Oviparous {
public:
	Crocodile(int t_TrackNum, string t_name, string t_type, string t_subType, int t_NumberOfEggs);
	virtual ~Crocodile();
};

#endif /* CROCODILE_H_ */
