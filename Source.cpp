#include <iostream>
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

protected:
	string itemName = "";
	float itemSpeed = 0.0f;
public:
	virtual ~WarpDrive() {}
	virtual string getName(void) { return this->itemName; }
	virtual float getSpeed(void) { return this->itemSpeed; }
	virtual void displayDrive(void) { cout << "Warp " << itemSpeed << "-rated " << itemName << endl; }
	virtual void start(void) { cout << "Firing up Warp Drive!" << endl; }
	virtual void engage(void) { cout << "Engaging Warp" << itemSpeed << "!" << endl; }
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

protected:
	WarpDrive* drive = nullptr;
public:
	~DriveEnhancement() { delete drive; }
	virtual string getName(void) { return drive->getName() + " + " + this->itemName; }
	virtual float getSpeed(void) { return this->itemSpeed + drive->getSpeed(); }
	virtual void addEnhancement(void) { cout << itemName << endl; }
	void addToWarpDrive(WarpDrive* drive) { this->drive = drive; };
	void start(void) { drive->start(); addEnhancement(); }
};
class StrongerContainmentField : public DriveEnhancement
{
	//purpose: inheriting DriveEnhancement subclass for Stronger Containment Field enhancement

public:
	StrongerContainmentField(void) { itemName = "Stronger Containment Field"; itemSpeed = 0.25f; }
};
class ReinforcedPlasmaInjectors : public DriveEnhancement
{
	//purpose: inheriting DriveEnhancement subclass for Reinforced Plasma Injectors enhancement

public:
	ReinforcedPlasmaInjectors(void) { itemName = "Reinforced Plasma Injectors"; itemSpeed = 0.5f; }
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
	UpratedWarpCoil(void) { itemName = "Uprated Warp Coil"; itemSpeed = 2.0f; }
};
#pragma endregion

int main(void)
{
	return 0;
}