#ifndef __CELL__
#define __CELL__

//forward declearation
class Critter;

class Cell {
public:
    Cell();
    void setCritter(Critter* c);
    void setBool(bool v);
    Critter* getCritter();
    bool getBool();
    void smartCheck();
private:
    bool haveCritter;
    Critter* ptr;
};

#endif