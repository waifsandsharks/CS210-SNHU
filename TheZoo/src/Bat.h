/*
 * Bat.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1771245_snhu
 */

#ifndef BAT_H_
#define BAT_H_

#include "Mammal.h"

class Bat : public Mammal {
public:
	Bat(int t_TrackNum, string t_name, string t_type, string t_subType, int t_Nurse);
	virtual ~Bat();
};

#endif /* BAT_H_ */
