/*
 * TheZoo.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: Ethan Daugherty 1771245_snhu
 *
 *      This program is designed to work in conjunction with a JAVA file(ZooFIleWriter.Java)
 *      to track animals by using such functions as, Load Animal Data, Generate Data,
 *       Display Animal Data, Add Record, Delete Record, and save Animal Data.
 */

// linking our other animal headers and animal type like mammal and Oviparous.
#include <iostream>
#include <string>
#include <jni.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Animal.h"
#include "Oviparous.h"
#include "Mammal.h"
#include "Crocodile.h"
#include "Goose.h"
#include "Pelican.h"
#include "Bat.h"
#include "Whale.h"
#include "SeaLion.h"

using namespace std;
void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

/*
 * Converts an int to a string and returns to string a
 * and vice versa for string to int.
 * Sourced from:
 * https://www.geeksforgeeks.org/converting-strings-numbers-cc/
 * On 02/20/2021
 *
 */
string NumberToString(int t_number) {
	ostringstream stringStream;
	stringStream << t_number;
	return stringStream.str();
}

int StringToNumber(string t_string) {
	try {
		int number = stoi(t_string);
		return number;
	}

	catch (invalid_argument &excpt) {
		cout << "Invalid data. Delete and retry.\n" << excpt.what() << "\n";
	}
}
/*
 * setw used to set up output spacing and design
 * sourced from:
 * http://www.cplusplus.com/reference/iomanip/setw/
 * retreived on:
 * 02/20/2021
 */
 void DisplayAnimalData(vector<Animal>& t_animalsList) {
	cout << left << setw(6) << "Track#" << " "
			<< left << setw(15) << "Name" << "  "
			<< left << setw(15) << "Type" << "  "
			<< left << setw(15) << "Sub-Type" << "  "
			<< left << setw(1) << "Eggs" << "  "
			<< left << setw(1) << "Nurse" << "  " << endl;

	if (t_animalsList.size() > 0) {
		for (unsigned int i = 0; i < t_animalsList.size(); ++i) {
			Animal animal = t_animalsList.at(i);
			string animalAttributes;
			ostringstream animalAttr;

			animalAttr << right << setfill('0') << setw(6) << animal.TrackNum << " ";
			animalAttr << left << setw(15) << setfill(' ') << animal.name << "  "
					<< left << setw(15) << animal.type << "  "
					<< left << setw(15) << animal.subType << "  ";
			auto padded{ animalAttr.str() };

			animalAttributes += padded;
			if (animal.type == "Mammal") {
				animalAttributes += "0     " + NumberToString(animal.additionalData); // Nurse
			}
			else {
				animalAttributes += NumberToString(animal.additionalData) + "     0"; // Eggs
			}

			cout << animalAttributes << "\n";
		}
	}
	else {
		cout << "\n to view current animals Select Load Animal.\n\n";
	}
 }
/* learned about using runtime_errors in the reading and looked into them further and setting thme up
 * on cplusplus.
 * Sourced from:
 * http://www.cplusplus.com/reference/stdexcept/runtime_error/
 * Retreived on:
 * 02/21/2021
 */
void AddAnimal(vector<Animal>& t_animalsList){
	int trackNumber;
	string animalName;
	string animalType;
	string subType;
	int numEggs;
	int nurse;
	char yKey;

	cout << "Track Number: ";
	cin >> setw(6) >> trackNumber;

	if (!cin) {
		throw runtime_error("Numbers only or not enough numbers. \n");
	}

	cout << "Enter Animal Name: ";
	cin >> setw(15) >> animalName;

	if (!cin) {
		throw runtime_error("Lets try again. \n");
	}

	cout << "Enter Animal Type: ";
	cin >> setw(15) >> animalType;

	if (!cin) {
		throw runtime_error("Lets try again. \n");
	}

	cout << "Enter Animal Sub-type: ";
	cin >> setw(15) >> subType;

	if (!cin) {
		throw runtime_error("Let try again. \n");
	}

	cout << "Enter Number of Eggs: ";
	cin >> setw(1) >> numEggs;

	if (!cin) {
		throw runtime_error("Numbers only. \n");
	}

	cout << "Enter 1 if Nursing, 0 if not: ";
	cin >> setw(1) >> nurse;

	if (!cin) {
		throw runtime_error("Numbers only 0 or 1. \n");
	}

	cout << "Save data? (Y or N)";
	cin >> yKey;
	yKey = toupper(yKey);

	/*
	 * Check to see if track # is already registered in array.
	 * if so it increments by 1 to the new matching record.
	 * idea for method sourced from:
	 * http://www.cplusplus.com/forum/beginner/189811/
	 * Retreived on: 02/20/2021
	 */
	if (yKey == 'Y') {
		int counter = 0;
		for (unsigned int i = 0; i < t_animalsList.size(); ++i) {
			Animal animalInVector = t_animalsList.at(i);
			if (trackNumber == animalInVector.TrackNum) {
				++counter;
			}
		}

		if (counter == 0){
			if (animalType == "Mammal") {
				Animal newAnimal(trackNumber, animalName, "Mammal", subType, nurse);
				t_animalsList.push_back(newAnimal);
			}

			else if (animalType == "Oviparous"){
				Animal newAnimal(trackNumber, animalName, "Oviparous", subType, numEggs);
				t_animalsList.push_back(newAnimal);
			}
			else {
				Animal newAnimal(trackNumber, animalName, animalType, subType, 0);
				t_animalsList.push_back(newAnimal);
			}

			cout << "\nAnimal saved \n" << endl;
		}
	}
	else {
		cout << "\nAnimal not saved \n" << endl;
	}
}

void RemoveAnimal(vector<Animal>& t_animalsList){
	cout << "To delete an animals record, enter the Track number." << endl;
	int trackNumber;
	cin >> trackNumber;

	if (!cin || trackNumber < 000001 || trackNumber > 999999) {
		throw runtime_error("\nNot in use. \n");
	}

	for (unsigned int i = 0; i < t_animalsList.size(); ++i) {
		Animal animalInVector = t_animalsList.at(i);
		if (animalInVector.TrackNum == trackNumber) {
			cout << "To delete this record press 'Y'. " << endl;
			char answer;
			cin >> answer;
			answer = toupper(answer);
			if (answer == 'Y') {
				t_animalsList.erase(t_animalsList.begin() + i);
				cout << "\nAnimal deleted. \n" << endl;
			}
			else {
				cout << "\nAnimal not deleted. \n" << endl;
				continue;
			}
		}
	}
}

void AddAnimalsToVector(vector<Animal>& t_animalsList, vector<string>& t_linesFromFile, bool fromJava = false) {
	for (unsigned int i = 0; i < t_linesFromFile.size(); ++i) {

		string track;
		string name;
		string type;
		string subType;
		string eggs;
		string nurse;

		try {
			if(fromJava) {
				track =  t_linesFromFile.at(i).substr(1, 6);
				name =  t_linesFromFile.at(i).substr(8, 15);
				type =  t_linesFromFile.at(i).substr(25, 15);
				subType = t_linesFromFile.at(i).substr(42, 15);
				eggs =  t_linesFromFile.at(i).substr(59, 1);
				nurse =  t_linesFromFile.at(i).substr(61, 1);
			}

			else {
				track =  t_linesFromFile.at(i).substr(0, 6);
				name =  t_linesFromFile.at(i).substr(7, 15);
				type =  t_linesFromFile.at(i).substr(24, 15);
				subType = t_linesFromFile.at(i).substr(41, 15);
				eggs =  t_linesFromFile.at(i).substr(58, 1);
				nurse =  t_linesFromFile.at(i).substr(60, 1);
			}
		} catch (out_of_range & ex) {
			cout << "Cannot unable to import Animal data. \n\n"
					"Ensure within parameters.\n\n";
		}

		int counter = 0;
		for (unsigned int j = 0; j < t_animalsList.size(); ++j) {
			Animal animalInVector = t_animalsList.at(j);
			if (StringToNumber(track) == animalInVector.TrackNum) {
				++counter;
			}
		}

		if (counter == 0){
			if(subType == "Crocodile"){
				Crocodile newCroc(StringToNumber(track), name, "Oviparous", subType, StringToNumber(eggs));
				t_animalsList.push_back(newCroc);
			}

			else if (subType == "Goose") {
				Goose newGoose(StringToNumber(track),name,"Oviparous", subType,StringToNumber(eggs));
				t_animalsList.push_back(newGoose);
			}

			else if (subType == "Pelican") {
				Pelican newPelly(StringToNumber(track), name,"Oviparous",subType,StringToNumber(eggs));
				t_animalsList.push_back(newPelly);
			}

			else if (subType == "Bat") {
				Bat newBat(StringToNumber(track),name,"Mammal",subType,StringToNumber(nurse));
				t_animalsList.push_back(newBat);
			}

			else if (subType == "Whale") {
				Whale newWhale(StringToNumber(track),name,"Mammal",subType,StringToNumber(nurse));
				t_animalsList.push_back(newWhale);
			}

			else if (subType == "SeaLion") {
				SeaLion newSeaLion(StringToNumber(track),name,"Mammal",subType,StringToNumber(nurse));
				t_animalsList.push_back(newSeaLion);
			}

			else {
				Animal newAnimal(StringToNumber(track),name,type,subType,0);
				t_animalsList.push_back(newAnimal);
			}
		}
	}
}
/*
 *  Was super confused on how to load data found information further on the forurms and tutorials on cplusplus
 *  super interesting and looking forward to learning more.
 *  Sourced from:
 * https://www.cplusplus.com/doc/tutorial/files/
 * https://www.cplusplus.com/doc/tutorial/basic_io/
 * https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm
 * https://stackoverflow.com/questions/20450482/return-an-ifstream-instance-to-use-in-another-function
 *  Retrevied on:
 *   02/20/2021
 */
void LoadDataFromFile(vector<Animal>& t_animalsList) {
	ifstream file1{"zoodata.txt"};
	string line1;
	vector<string> linesFromFile1;

	while (getline(file1, line1)) {
		linesFromFile1.push_back(line1);
	}

	AddAnimalsToVector(t_animalsList, linesFromFile1, true);
	file1.close();
	remove("zoodata.txt");

	ifstream file2{"composite-zoodata.txt"};
	string line2;
	vector<string> linesFromFile2;

	while (getline(file2, line2)) {
		linesFromFile2.push_back(line2);
	}

	AddAnimalsToVector(t_animalsList, linesFromFile2);
	file2.close();
	cout << "\nLoad complete.\n";
}

void SaveDataToFile(vector<Animal>& t_animalsList){
	ofstream outputFile{"composite-zoodata.txt"};
	for (unsigned int i = 0; i < t_animalsList.size(); ++i) {
		Animal animal = t_animalsList.at(i);
		string animalAttributes;
		ostringstream animalAttr;

		animalAttr << right << setfill('0') << setw(6) << animal.TrackNum << " ";
		animalAttr	<< left << setfill(' ') << setw(15) << animal.name << "  "
				<< left << setw(15) << animal.type << "  "
				<< left << setw(15) << animal.subType << "  ";
		auto padded{ animalAttr.str() };

		animalAttributes += padded;
		if (animal.type == "Mammal") {
			animalAttributes += "0 " + NumberToString(animal.additionalData);
		}

		else {
			animalAttributes += NumberToString(animal.additionalData) + " 0";
		}

		outputFile << animalAttributes << "\n";
	}

	outputFile.close();
	cout << "\nSave complete.\n";

}


void DirectTraffic(vector<Animal>& t_animalsList, int t_userSelection) {
	switch(t_userSelection) {
		case 1:
			LoadDataFromFile(t_animalsList);
			break;
		case 2:
			GenerateData();
			cout << "\n By selecting Load Animal Data do you want to add it to the animals on file?\n";
			break;
		case 3:
			DisplayAnimalData(t_animalsList);
			break;
		case 4:
			AddAnimal(t_animalsList);
			break;
		case 5:
			RemoveAnimal(t_animalsList);
			break;
		case 6:
			SaveDataToFile(t_animalsList);
			break;
		default:
			throw runtime_error("Try again. \n");
	}
}
/*Learned a lot about menu creation and functionality from Cplusplus
 * Souced from:
 * https://www.cplusplus.com/forum/beginner/267226/
 * Sourced on:
 * 02/21/2021
 */


void DisplayMenu(vector<Animal>& t_animalsList)
{
	char quitCmd = 'a';
	int userSelection;
	vector<string> menuOptions = { "Welcome please choose", "[1] Load Animal-Data", "[2] Generate Data",
			"[3] Display Animal-Data", "[4] Add New Record", "[5] Delete Saved Record", "[6] Save Animal-Data",
			"[7] Quit"};

	while (quitCmd != 'q') {
		try {
			cout << "\n";
			for (unsigned int i = 0; i < menuOptions.size(); ++i){
				cout << menuOptions.at(i) << endl;
			}

			cin >> userSelection;
			if (!cin || userSelection < 1 || userSelection > 7) {
				throw runtime_error("Try again. \n");
			}

			if (userSelection == 7) {
				cout << "\nGoodbye.\n";
				quitCmd = 'q';
			}
			else {
				DirectTraffic(t_animalsList, userSelection);
			}
		}
		catch(runtime_error& except) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << except.what() << endl;
		}
	}
}

int main()
{
	vector<Animal> animalsList; //
	try {
		DisplayMenu(animalsList);
	}
	catch(runtime_error& excpt) {
		cout << "lets try that again...." << "\n";
	}

	return 1;
}
