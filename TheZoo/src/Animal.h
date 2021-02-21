/*
 * Animal.h

 *
 *  Created on: Feb 20, 2021
 *  Author: Ethan Daugherty 1771245_snhu
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include<iostream>
using namespace std;

class Animal {
public:
	Animal(int t_TrackNum, string t_name, string t_type, string t_subType, int additionalData);
	virtual ~Animal();
	int TrackNum;
	string name;
	string type;
	string subType;
	int additionalData;
};

#endif /* ANIMAL_H_ */
