#include <iostream>         // Standard Input/Output operations
#include <random>           // Random number generation facilities
#include <limits>           // Numeric limits, used for input validation
#include <cstdlib>          // General utilities, including function for converting string to integer
#include "PerfectSolid.h"   // Contains the declarations for perfect solids

using namespace std;

// Objects representing perfect solids
const Tetrahedron tetrahedron;
const Hexahedron hexahedron;
const Octahedron octahedron;
const Dodecahedron dodecahedron;
const Icosahedron icosahedron;

// Random number generator setup
random_device rd;
mt19937 engine(rd());

// Global variable to store the sum of all dice rolls
int sumOfSums = 0;

/**
 * @brief Generates a random number between 1 and the specified maximum value.
 * @param max The maximum value for the random number.
 * @return The generated random number.
 */
int getRandomNumber(int max) {
    if (max <= 1) {
        cerr << "Error: Invalid argument for getRandomNumber.\n";
        // Handle the error or return an appropriate value.
        return -1;
    }

    uniform_int_distribution<> distribution(1, max);
    return distribution(engine);
}

/**
 * @brief Generates and prints random numbers for a polyhedron.
 * @param polyhedronName The name of the polyhedron.
 * @param numberOfRolls The number of rolls for the polyhedron.
 * @param numberOfFaces The number of faces for the polyhedron.
 */
void generateRandomNumbersForPolyhedron(const string& polyhedronName, int numberOfRolls, int numberOfFaces) {
    cout << endl << polyhedronName << ": ";
    int sum = 0;

    for (auto c = 1; c <= numberOfRolls; c++) {
        int randomNumber = getRandomNumber(numberOfFaces);
        sum += randomNumber;
        sumOfSums += randomNumber;
        cout << randomNumber << " ";
    }
    cout << "\nSum: " << sum << endl;
}

int main() {
    cout << "   PERFECT DICE ROLLER\n\n";

    cout << "// Number of rolls\n";

    // Getting the number of rolls for each polyhedron from user inputs
    int numberOfTetrahedronRolls, numberOfHexahedronRolls, numberOfOctahedronRolls, numberOfDodecahedronRolls, numberOfIcosahedronRolls;

    cout << "Tetrahedron: ";
    if (!(cin >> numberOfTetrahedronRolls)) {
        cerr << "Error: Invalid input for Tetrahedron.\n";
        return 1;
    }

    cout << "Hexahedron: ";
    if (!(cin >> numberOfHexahedronRolls)) {
        cerr << "Error: Invalid input for Hexahedron.\n";
        return 1;
    }

    cout << "Octahedron: ";
    if (!(cin >> numberOfOctahedronRolls)) {
        cerr << "Error: Invalid input for Octahedron.\n";
        return 1;
    }

    cout << "Dodecahedron: ";
    if (!(cin >> numberOfDodecahedronRolls)) {
        cerr << "Error: Invalid input for Dodecahedron.\n";
        return 1;
    }

    cout << "Icosahedron: ";
    if (!(cin >> numberOfIcosahedronRolls)) {
        cerr << "Error: Invalid input for Icosahedron.\n";
        return 1;
    }

    // Generates and prints random numbers for each polyhedron based on user input of the number of rolls
    generateRandomNumbersForPolyhedron("Tetrahedron", numberOfTetrahedronRolls, tetrahedron.getNumberOfFaces());
    generateRandomNumbersForPolyhedron("Hexahedron", numberOfHexahedronRolls, hexahedron.getNumberOfFaces());
    generateRandomNumbersForPolyhedron("Octahedron", numberOfOctahedronRolls, octahedron.getNumberOfFaces());
    generateRandomNumbersForPolyhedron("Dodecahedron", numberOfDodecahedronRolls, dodecahedron.getNumberOfFaces());
    generateRandomNumbersForPolyhedron("Icosahedron", numberOfIcosahedronRolls, icosahedron.getNumberOfFaces());

    // Prints the total sum of all dice rolls
    cout << "\nSum of sums: " << sumOfSums;

    return 0;
}
