//
// Created by grimk on 10/8/2023.
//
#include "Inventory.h"

Inventory::Inventory() = default;


Inventory::Inventory(Inventory::EquipmentType type, const std::string &weaponName, int durability, int lowDmg,
                     int highDmg, int critChance, float dps, Inventory::Rarity rarity) {

}

void Inventory::displayInventory() {

}

/**
 * overloaded operator that
 * defines whether something is greater than
 * based on the rarity of it
 * Will be used later for suggesting if the user should replace it or not
 * @param other
 * @return boolean
 */
bool Inventory::operator<(const Inventory &other) const {
    const std::map<Rarity,int> rarityOrder = {
            { Rarity::Boring, 0},
            { Rarity::Cool, 1},
            { Rarity:: Epic, 2},
            { Rarity::Awesome, 3},
            { Rarity::Insane, 4},
            { Rarity::Godly, 5}
    };

    if (rarityOrder.find(rarity_) != rarityOrder.end() &&
        rarityOrder.find(other.rarity_) != rarityOrder.end()) {
        return rarityOrder.at(rarity_) < rarityOrder.at(other.rarity_);
    }
    return false;
}

void Inventory::displayInfo(std::vector<Inventory> &equipmentInventory) const {

}

