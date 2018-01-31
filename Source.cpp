/*
	Decorator design pattern test
	Khalid Ali 2018

	Legal:
		Star Trek and its branding is copyright of CBS Studios Inc.
		References to the branding are included under the legally-acknowledged terms of "fair use"

	Using:
		1) create WarpDrive pointer with new object as the WarpDrive subtype you want (check "Warp Drives" region for list)
			1.5) use getName() and getSpeed() to test the base drive's characteristics
		2) create DriveEnhancement pointer with new object as the DriveEnhancement subtype you want (check "Drive Enhancements" region for list)
		3) pass WarpDrive pointer created in 1) through method addToWarpDrive to bind WarpDrive to DriveEnhancement
			3.5) if you want to add more enhancements, just assign a new DriveEnhancement to the same DriveEnhancement pointer and repeat step 3)
		4) use getName() and getSpeed() to test the resultant drive's characteristics

	Other Notes:
		Based on a tutorial from University module for Data Structures & Algorithms for Object-Orientated Programming
		Already complete usage example provided in main() function
*/


#include <iostream>
#include <iomanip> //can be removed if setprecision() for cout is not needed
#include <string>

using namespace std;

#pragma region Warp Drives
/*
	purpose: object representation of Warp Drives and various subtypes
	subtypes:
		Nuclear Fission drive
		Nuclear Fusion drive
		Quantum Singularity drive
		Matter/Antimatter drive
*/

class WarpDrive
{
	//purpose: abstract superclass for all Warp Drives
	//note: never initialise - only use for pointer declaration

protected:
	WarpDrive() {};
	string itemName = "";
	float itemSpeed = 0.0f;
public:
	virtual ~WarpDrive() {}
	virtual string getName(void) { return this->itemName; }
	virtual float getSpeed(void) { return this->itemSpeed; }
};
class NuclearFissionDrive : public WarpDrive
{
	//purpose: inheriting WarpDrive subclass for Nuclear Fission drive

public:
	NuclearFissionDrive(void) { itemName = "Nuclear Fission drive"; itemSpeed = 1.0f; }
};
class NuclearFusionDrive : public WarpDrive
{
	//purpose: inheriting WarpDrive subclass for Nuclear Fusion drive

public:
	NuclearFusionDrive(void) { itemName = "Nuclear Fusion drive"; itemSpeed = 4.0f; }
};
class QuantumSingularityDrive : public WarpDrive
{
	//purpose: inheriting WarpDrive subclass for Quantum Singularity drive

public:
	QuantumSingularityDrive(void) { itemName = "Quantum Singularity drive"; itemSpeed = 6.5f; }
};
class MatterAntimatterDrive : public WarpDrive
{
	//purpose: inheriting WarpDrive subclass for Matter/Antimatter drive

public:
	MatterAntimatterDrive(void) { itemName = "Matter/Antimatter drive"; itemSpeed = 7.0f; }
};
#pragma endregion

#pragma region Drive Enhancements
/*
	purpose: object representation of a WarpDrive decorator
	subtypes:
		Stronger Containment Field
		Reinforced Plasma Injectors
		Purer Dilithium Crystals
		Uprated Warp Coil
*/

class DriveEnhancement : public WarpDrive
{
	//purpose: abstract superclass for all Drive Enhancements
	//note: never initialise - only use for pointer declaration

protected:
	DriveEnhancement() {};
	WarpDrive* drive = nullptr;
public:
	~DriveEnhancement() { delete drive; }
	virtual string getName(void) { return drive->getName() + " + " + this->itemName; }
	virtual float getSpeed(void) { return this->itemSpeed + drive->getSpeed(); }
	void addToWarpDrive(WarpDrive* drive) { this->drive = drive; };
};
class StrongerContainmentField : public DriveEnhancement
{
	//purpose: inheriting DriveEnhancement subclass for Stronger Containment Field enhancement

public:
	StrongerContainmentField(void) { itemName = "Stronger Containment Field"; itemSpeed = 0.125f; }
};
class ReinforcedPlasmaInjectors : public DriveEnhancement
{
	//purpose: inheriting DriveEnhancement subclass for Reinforced Plasma Injectors enhancement

public:
	ReinforcedPlasmaInjectors(void) { itemName = "Reinforced Plasma Injectors"; itemSpeed = 0.25f; }
};
class PurerDilithiumCrystals : public DriveEnhancement
{
	//purpose: inheriting DriveEnhancement subclass for Purer Dilithium Crystals enhancement

public:
	PurerDilithiumCrystals(void) { itemName = "Purer Dilithium Crystals"; itemSpeed = 1.0f; }
};
class UpratedWarpCoil : public DriveEnhancement
{
	//purpose: inheriting DriveEnhancement subclass for Uprated Warp Coil enhancement

public:
	UpratedWarpCoil(void) { itemName = "Uprated Warp Coil"; itemSpeed = 1.5f; }
};
#pragma endregion

int main(void)
{
	//decorator pattern example with a Warp Drive upgrade

	//initial warp drive
	WarpDrive* currentDrive = new MatterAntimatterDrive;
	
	//test initial warp drive
	cout << "This is a " << currentDrive->getName() << endl;
	cout << "Engage, Warp " << currentDrive->getSpeed() << setprecision(3) << "!" << endl;

	//apply all available upgrades
	DriveEnhancement* currentEnhancement = new UpratedWarpCoil;
	currentEnhancement->addToWarpDrive(currentDrive);
	currentDrive = currentEnhancement;
	currentEnhancement = new StrongerContainmentField;
	currentEnhancement->addToWarpDrive(currentDrive);
	currentDrive = currentEnhancement;
	currentEnhancement = new PurerDilithiumCrystals;
	currentEnhancement->addToWarpDrive(currentDrive);
	currentDrive = currentEnhancement;
	currentEnhancement = new ReinforcedPlasmaInjectors;
	currentEnhancement->addToWarpDrive(currentDrive);
	currentDrive = currentEnhancement;

	//test enhanced warp drive
	cout << endl << "This is a " << currentDrive->getName() << endl;
	cout << "Engage, Warp " << currentDrive->getSpeed() << setprecision(3) << "!" << endl;

	delete currentDrive;
	return 0; //put breakpoint here to stop program to exiting straight away
}