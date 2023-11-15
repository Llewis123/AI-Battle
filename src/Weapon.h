/**
 * Weapon.h will have enum classes and structures
 * to define a weapon and its many properties, including rarity and its type
 * will also display inventory and weapon information
 */

#ifndef M1OEP_WEAPON_H
#define M1OEP_WEAPON_H


#include "Inventory.h"

/**
 * enum class for different weapon types
 * will add more, just needed the ones
 * for the default character
 */




class Weapon : public Inventory{

protected:
    struct WeaponProperties{
        std::string weaponName;
        int durability;
        int lowDmg;
        int highDmg;
        int critChance;
        float dps;


    };
    WeaponProperties properties_;
    Rarity rarity_;
    EquipmentType type_;

public:
    Weapon();

    Weapon(EquipmentType type,const std::string& weaponName, int durability, int lowDmg, int highDmg, int critChance, float dps, Rarity rarity);
    void displayInventory() override;
    virtual void displayInfo(std::vector<Weapon>& weaponsInventory) const;

};





#endif //M1OEP_WEAPON_H
