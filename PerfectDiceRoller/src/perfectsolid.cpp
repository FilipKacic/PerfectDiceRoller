#include "PerfectSolid.h"

PerfectSolid::PerfectSolid() {
}

PerfectSolid::~PerfectSolid() {
}

int PerfectSolid::getNumberOfFaces() const {
    return numberOfFaces;
}

void PerfectSolid::setNumberOfFaces(int faces) {
    numberOfFaces = faces;
}

Tetrahedron::Tetrahedron() {
    setNumberOfFaces(4);
}

Hexahedron::Hexahedron() {
    setNumberOfFaces(6);
}

Octahedron::Octahedron() {
    setNumberOfFaces(8);
}

Dodecahedron::Dodecahedron() {
    setNumberOfFaces(12);
}

Icosahedron::Icosahedron() {
    setNumberOfFaces(20);
}
