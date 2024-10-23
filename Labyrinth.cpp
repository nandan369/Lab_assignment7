#include "Labyrinth.h"

/**-------------------------------------------------------------------------------
 * Functions: isPathToFreedom(start, moves)
 * _______________________________________________________________________________
 * This function checks if a path through the maze allows collection of all items (spellbook, potion, wand).
 * Starts from the given cell and processes each move direction.
 * If a move leads to a valid cell, it checks for items and updates collection status.
 * Returns true if all items are collected, either during traversal or at the end of the moves.
 ---------------------------------------------------------------------------------*/
bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    // Boolean variables to track whether we have collected all items
    bool hasSpellbook = false, hasPotion = false, hasWand = false;

    // Start at the initial location
    MazeCell* current = start;

    // Check the initial location for an item
    switch (current->whatsHere) {
        case Item::SPELLBOOK: hasSpellbook = true; break;
        case Item::POTION: hasPotion = true; break;
        case Item::WAND: hasWand = true; break;
        default: break;
    }

    // Loop through the path directions
    for (char move : moves) {
        // Move in the specified direction
        MazeCell* next = nullptr; // Temporary variable for the next cell

        switch (move) {
            case 'N': next = current->north; break;
            case 'S': next = current->south; break;
            case 'E': next = current->east; break;
            case 'W': next = current->west; break;
            default: return false; // Invalid move
        }

        // Check if the move is legal
        if (next == nullptr) {
            return false; // Illegal move, no cell in that direction
        }

        // Move to the next cell
        current = next;

        // Check if the current location contains an item
        switch (current->whatsHere) {
            case Item::SPELLBOOK: hasSpellbook = true; break;
            case Item::POTION: hasPotion = true; break;
            case Item::WAND: hasWand = true; break;
            default: break;
        }

        // Check if all items have been collected
        if (hasSpellbook && hasPotion && hasWand) {
            return true; // Early exit if all items collected
        }
    }

    // Return true only if all items have been collected by the end of the moves
    return hasSpellbook && hasPotion && hasWand;
}