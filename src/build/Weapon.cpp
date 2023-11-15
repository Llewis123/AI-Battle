/**
 * Weapon.h script file
 */
#include "Weapon.h"

// Cool syntax for constructor ;)
Weapon::Weapon(EquipmentType type, const std::string &weaponName, int durability, int lowDmg,
                     int highDmg, int critChance, float dps, Rarity rarity) : type_(type),
                     properties_({weaponName, durability, lowDmg, highDmg, critChance,dps}),
                     rarity_(rarity)
                     {}





/**
 * Initializes a default inventory,
 * Later will chance to have a priavate weapons inventory vector to keep a running track of inventory.
 */
void Weapon::displayInventory() {
    std::vector<Weapon> weaponsInventory;
    // Default values of cahracter

    Weapon laserKatana(EquipmentType::laserKatana,"CosmoCorp Basic Laser Katana  KX500",50,5,10,7,6.2,Rarity::Boring);
    Weapon machinePistol(EquipmentType::machinePistol,"CosmoCorp Basic Machine Pistol MX125",100,1,5,1,5.2,Rarity::Boring);
    Weapon laserRifle(EquipmentType::laserRifle,"CosmoCorp Basic Laser Rifle LX125",25,10,15,8,6.8,Rarity::Boring);

    // vector to store the weapons

    weaponsInventory.push_back(laserKatana);
    weaponsInventory.push_back(machinePistol);
    weaponsInventory.push_back(laserRifle);

    displayInfo(weaponsInventory);

    // Print out the items and values in each weapon

}
/**
 * Prints out weapon inventory based on the
 * current weaponsInventory vector
 * @param weaponsInventory
 */
void Weapon::displayInfo(std::vector<Weapon> &weaponsInventory) const {

    for (const Weapon &other : weaponsInventory){

        std::cout<< other.properties_.weaponName << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout<< "Rarity: ";
        switch (other.rarity_){
            case Rarity::Boring:
                std::cout << "Boring" << std::endl;
                break;
            case Rarity::Cool:
                std::cout << "Cool" << std::endl;
                break;
            case Rarity::Epic:
                std::cout << "Epic" << std::endl;
                break;
            case Rarity::Awesome:
                std::cout << "Awesome" << std::endl;
                break;
            case Rarity::Insane:
                std::cout << "Insane" << std::endl;
                break;
            case Rarity::Godly:
                std::cout << "Godly" << std::endl;
                break;
        }
        std::cout << "Durability : " << other.properties_.durability << std::endl;
        std::cout << "Low damage : " << other.properties_.lowDmg << std::endl;
        std::cout << "High damage : " << other.properties_.highDmg << std::endl;
        std::cout << "Critical Chance : " << (other.properties_.critChance) << "%" << std::endl;
        std::cout << "DPS : " << other.properties_.dps << "Per second" << std::endl;

    }




}
// default constructor for calling purposes
Weapon::Weapon() : Inventory() {}







