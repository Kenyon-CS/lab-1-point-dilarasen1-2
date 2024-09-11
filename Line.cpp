// Line.cpp
#include "Line.h"
#include "Point.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

/**
 * Default constructor for the Line class.
 * Purpose: Initializes a Line object with default coefficients (0.0, 0.0, 0.0).
 * Preconditions: None.
 * Postconditions: A Line object is created with coefficients a = 0.0, b = 0.0, c = 0.0.
 */
Line::Line() : a(0.0), b(0.0), c(0.0) {}

/**
 * Parameterized constructor for the Line class.
 * Purpose: Initializes a Line object with specified coefficients.
 * Preconditions: 'a' and 'b' should not both be zero.
 * Postconditions: A Line object is created with the given coefficients.
 * @param a Coefficient for x.
 * @param b Coefficient for y.
 * @param c Constant term.
 * Throws: std::invalid_argument if both 'a' and 'b' are zero.
 */
Line::Line(double a, double b, double c) : a(a), b(b), c(c) {
    // Check that a and b do not equal zero
    if (a == 0.0 && b == 0.0) {
        throw std::invalid_argument("Invalid: Both a and b cannot be zero.");
    }
}

/**
 * Calculates the slope of the line.
 * Purpose: Returns the slope of the line.
 * Preconditions: 'b' must not be zero (the line should not be vertical).
 * Postconditions: The slope of the line is returned.
 * @return double The slope of the line.
 * Throws: std::runtime_error if the slope is undefined (vertical line).
 */
double Line::slope() const {
    // Check to make sure the line is not vertical
    if (b == 0.0) {
        throw std::runtime_error("Slope is undefined because it is a vertical line.");
    }
    return -a / b;
}

/**
 * Equality operator overload for comparing two lines.
 * Purpose: Checks if two lines are equal by comparing their coefficients.
 * Preconditions: Both Line objects are initialized with valid coefficients.
 * Postconditions: Returns true if lines are equal, false otherwise.
 * @param other The Line object to compare with.
 * @return bool True if the lines are equal, otherwise false.
 */
bool Line::operator==(const Line& other) const {
    // Considers the lines are equal if the coefficients are proportional
    return (a * other.b == b * other.a) && (a * other.c == c * other.a) && (b * other.c == c * other.b);
}

/**
 * OR operator overload for checking if two lines are parallel.
 * Purpose: Determines if two lines are parallel by comparing their slopes.
 * Preconditions: Both Line objects are initialized with valid coefficients.
 * Postconditions: Returns true if the lines are parallel, false otherwise.
 * @param other The Line object to compare with.
 * @return bool True if the lines are parallel, otherwise false.
 */
bool Line::operator||(const Line& other) const {
    // Considers two lines are parallel if a and b are proportional
    return (a * other.b == b * other.a);
}

/**
 * OR operator overload for checking if two lines are perpendicular.
 * Purpose: Determines if two lines are perpendicular by comparing their slopes.
 * Preconditions: Both Line objects are initialized with valid coefficients.
 * Postconditions: Returns true if the lines are perpendicular, false otherwise.
 * @param other The Line object to compare with.
 * @return bool True if the lines are perpendicular, otherwise false.
 */
bool Line::operator|(const Line& other) const {
    // Considers two lines are perpendicular if the product of the slope is -1
    if (b == 0 || other.b == 0) {
        return (a == 0 && other.b == 0) || (other.a == 0 && b == 0);    
    }
    return (a * other.a + b * other.b == 0);
}

/**
 * Finds the intersection point of two lines.
 * Purpose: Calculates the intersection point of the current line with another line.
 * Preconditions: Both Line objects are initialized with valid coefficients.
 * Postconditions: Returns a pointer to the Point object representing the intersection point, or nullptr if lines do not intersect.
 * @param other The Line object to find the intersection with.
 * @return Point* Pointer to the Point object representing the intersection point, or nullptr if lines do not intersect.
 */
Point* Line::intersect(const Line& other) const {
    // Calculate the determinant
    double det = a * other.b - other.a * b;

    if (det == 0) {
        // No intersection if the lines are parallel
        return nullptr;
    } else {
        // Calculate the x and y coordinates of the intersection point
        double x = (b * other.c - other.b * c) / det;
        double y = (other.a * c - a * other.c) / det;

        // Return the intersection point
        return new Point(x, y);
    }
}

/**
 * Prints the line information.
 * Purpose: Outputs the equation of the line in standard form.
 * Preconditions: The Line object is initialized with valid coefficients.
 * Postconditions: The line equation is printed to the standard output.
 */
    void Line::print() const {
        std::cout << "Line equation: "
                  << a << "x + "
                  << b << "y + "
                  << c << " = 0" << std::endl;
    }