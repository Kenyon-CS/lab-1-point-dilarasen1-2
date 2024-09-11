// Line.h
#ifndef LINE_H
#define LINE_H

#include "Point.h" 
#include <iostream>

class Line {
private:
    double a;
    double b;
    double c;
   
public:
    // Default constructor
    Line();

    // Parameterized constructor
    Line(double a, double b, double c);

    // Find the slope
    double slope() const;

    // Equality operator overload
    bool operator==(const Line& other) const;

    // Parallel operator overload
    bool operator||(const Line& other) const;

    // Perpendicular operator overload
    bool operator|(const Line& other) const;

    // Find the intersection point of two lines
    Point* intersect(const Line& other) const;

    // Print the line information
    void print() const; 
};

#endif
