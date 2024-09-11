// Point.cpp
#include "Point.h"
#include <cmath>

/**
 * Default constructor for the Point class.
 * Purpose: Initializes a Point object at the origin (0, 0).
 * Preconditions: None.
 * Postconditions: A Point object is created with x = 0 and y = 0.
 */
Point::Point() : x(0.0), y(0.0) {}

/**
 * Parameterized constructor for the Point class.
 * Purpose: Initializes a Point object with specific x and y coordinates.
 * Preconditions: None.
 * Postconditions: A Point object is created with the specified x and y coordinates.
 * @param xVal The x coordinate of the point.
 * @param yVal The y coordinate of the point.
 */
Point::Point(double xVal, double yVal) : x(xVal), y(yVal) {}

/**
 * Equality operator overload for comparing two points.
 * Purpose: Checks if two points have the same x and y coordinates.
 * Preconditions: Both Point objects are initialized with valid coordinates.
 * Postconditions: Returns true if the points are equal, false otherwise.
 * @param other The Point object to compare with.
 * @return bool True if the points have the same coordinates, otherwise false.
 */
bool Point::operator==(const Point& other) const {
    return (x == other.x) && (y == other.y);
}

/**
 * Subtraction operator overload to calculate the distance between two points.
 * Purpose: Computes the Euclidean distance between two points.
 * Preconditions: Both Point objects are initialized with valid coordinates.
 * Postconditions: Returns the distance between the two points.
 * @param other The Point object to calculate the distance to.
 * @return double The Euclidean distance between the two points.
 */
double Point::operator-(const Point& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

/**
 * Getter for the x coordinate.
 * Purpose: Returns the x coordinate of the point.
 * Preconditions: The Point object is initialized with a valid x coordinate.
 * Postconditions: The x coordinate of the point is returned.
 * @return double The x coordinate of the point.
 */
double Point::GetX() const {
    return x;
}

/**
 * Getter for the y coordinate.
 * Purpose: Returns the y coordinate of the point.
 * Preconditions: The Point object is initialized with a valid y coordinate.
 * Postconditions: The y coordinate of the point is returned.
 * @return double The y coordinate of the point.
 */
double Point::GetY() const {
    return y;
}

/**
 * Setter for the x coordinate.
 * Purpose: Sets the x coordinate of the point.
 * Preconditions: None.
 * Postconditions: The x coordinate of the point is updated.
 * @param xVal The new x coordinate.
 */
void Point::SetX(double xVal) {
    x = xVal;
}

/**
 * Setter for the y coordinate.
 * Purpose: Sets the y coordinate of the point.
 * Preconditions: None.
 * Postconditions: The y coordinate of the point is updated.
 * @param yVal The new y coordinate.
 */
void Point::SetY(double yVal) {
    y = yVal;
}
