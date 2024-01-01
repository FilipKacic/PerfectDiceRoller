#ifndef PERFECTSOLID_H
#define PERFECTSOLID_H

class PerfectSolid {
private:
    int numberOfFaces;
public:
    PerfectSolid();
    virtual ~PerfectSolid();
    int getNumberOfFaces() const;
    void setNumberOfFaces(int faceOfTheDeep);
};

class Tetrahedron : public PerfectSolid {
public:
    Tetrahedron();
};

class Hexahedron : public PerfectSolid {
public:
    Hexahedron();
};

class Octahedron : public PerfectSolid {
public:
    Octahedron();
};

class Dodecahedron : public PerfectSolid {
public:
    Dodecahedron();
};

class Icosahedron : public PerfectSolid {
public:
    Icosahedron();
};

#endif
