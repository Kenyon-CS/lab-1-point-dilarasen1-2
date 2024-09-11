// Dilara Sen, Josh Temple, Luke Wilson

// This program takes two lines and finds the point of intersection, if there is one

// We each contributed about equally to the development of the program and we followed the guidelines for Pair Programming

#include <iostream>
#include "Point.h"
#include "Line.h"

/**
 * The main function for the program.
 * Purpose: Creates two Line objects, finds their intersection point, and prints the result.
 * Preconditions: None.
 * Postconditions: Outputs the equations of the lines and their intersection point, if it exists.
 * @return int Returns 0 on successful execution.
 */
int main() {
    try {
        //Creates two Lines
        Line line1(1, 2, 3);
        Line line2(2, -1, 5);

        //Print line information
        line1.print(); //Print line1
        line2.print(); //Print line2

        /**
        * Checks if line1 and line2 are the same.
        * Purpose: To determine whether two lines are identical by comparing their coefficients.
         * Preconditions: Both line1 and line2 are valid Line objects.
        * Postconditions: Outputs whether the lines are the same or not.
         * @param line2 The second Line object to compare with line1.
        * @return bool True if the lines are identical, otherwise False.
         */
        if (line1 == line2) {
            std::cout << "The lines are the same." << std::endl;
        } else {}

        /**
         * Finds the intersection point of line1 and line2.
         * Precondition: Both lines are defined with valid coefficients.
         * Postcondition: Returns the intersection point of the two lines, if it exists.
         * @param line2 The second line object to find the intersection with.
         * @return Point* Pointer to the Point object representing the intersection point, or nullptr if lines do not intersect.
         */
        Point* intersectionPoint = line1.intersect(line2);

        if (intersectionPoint) {
            // If there is an intersection point, it will print it
            std::cout << "The lines intersect at (" << intersectionPoint->GetX() 
                      << ", " << intersectionPoint->GetY() << ")." << std::endl;
            //Frees the memory for the intersection point
            delete intersectionPoint;
        } else {
            std::cout << "The lines do not intersect." << std::endl;
        }

    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }

    return 0;

}
