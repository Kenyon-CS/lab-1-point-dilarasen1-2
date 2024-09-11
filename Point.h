// Point.h
#ifndef POINT_H
#define POINT_H

class Point {
public:
    double x;
    double y;

    // Default constructor
    Point();

    // Parameterized constructor
    Point(double xVal, double yVal);

    // Equality operator overload
    bool operator==(const Point& other) const;

    // Subtraction operator overload to calculate distance between points
    double operator-(const Point& other) const;

    // Getter for x coordinate
    double GetX() const;

    // Getter for y coordinate
    double GetY() const;

    // Setter for x coordinate
    void SetX(double xVal);

    // Setter for y coordinate
    void SetY(double yVal);
};

#endif
