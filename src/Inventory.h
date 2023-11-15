//
// Created by grimk on 10/5/2023.
//

#ifndef M1OEP_INVENTORY_H
#define M1OEP_INVENTORY_H

#include <string>
#include <iostream>
#include <map>
#include <vector>

/**
 * There are three types of inventories
 * one is a weapons inventory, in which there should be an enum for weapon type
 * and a struct for weapon properties
 *
 * There is also an armor inventory,
 * which will include shields as they would have an armor rating
 * there are types of armors, chest, leg, helmet
 *
 * There is a third type of inventory...
 * cyberbiotic enhancements...
 * this will be a huge amount of different types, basically we will categorize them
 * via melee, gun weapons, armor, kinetics (eyesight, movement speed, jump height)
 * and the more rarer type, which give a special ability of a sort
 * Each character can have a maximum of 5 cyberbiotic enhancements base level,
 * and +1 every boss they take out
 *
 *
 *
 *
 * If we call this class's print inventory, it will print the entire thing in a nice menu
 * otherwise, it will print just the thing you are looking for 
 */
class Inventory{

public:

    enum class EquipmentType {
        laserKatana,
        machinePistol,
        laserRifle,
        cyberHelmet,
        cyberChestplate,
        cyberLeggings,
        chestPlate,
        leggings,
        Helmet
    };
    enum class Rarity {
        Boring,
        Cool,
        Epic,
        Awesome,
        Insane,
        Godly
    };



    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: just needed for calling purposes
     */
    Inventory();
    /**
     * Requires:
     * @param type
     * @param weaponName
     * @param durability
     * @param lowDmg
     * @param highDmg
     * @param critChance
     * @param dps
     * @param rarity
     * Modifies & Effects: init weaponName and equipment types
     * TODO: Need to add the other inventory types
     */
    Inventory(EquipmentType type,const std::string& weaponName, int durability, int lowDmg, int highDmg, int critChance, float dps, Rarity rarity);



    virtual ~Inventory() = default;



    virtual void displayInventory();

    virtual bool operator<(const Inventory& other) const;

    virtual void displayInfo(std::vector<Inventory>& equipmentInventory) const;

    Rarity rarity_;


protected:


};






#endif //M1OEP_INVENTORY_H
