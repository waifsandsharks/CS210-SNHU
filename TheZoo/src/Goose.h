/*
 * Goose.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1771245_snhu
 */
#ifndef GOOSE_H_
#define GOOSE_H_

#include "Oviparous.h"

class Goose : public Oviparous {
public:
	Goose(int t_TrackNum, string t_name, string t_type, string t_subType, int t_NumberOfEggs);
	virtual ~Goose();
};

#endif /* GOOSE_H_ */
