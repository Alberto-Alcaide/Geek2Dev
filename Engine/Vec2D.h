#ifndef VEC2_H
#define VEC2_H

#include <iostream>

struct Vec2D
{
    float x;
    float y;
    
    /**
     * Default constructor
     */
    Vec2D();

    /**
     * Constructs a Vec2D object with given x and y components.
     *
     * @param x The x component of the vector.
     * @param y The y component of the vector.
     */
    Vec2D(float x, float y);

    /**
     * Destructor for the Vec2D object.
     */
    ~Vec2D() = default;

    /**
     * Adds a vector to the caller.
     *
     * @param v The vector to add.
     */
    void add(const Vec2D& v);

    /**
     * Subtracts a vector from the caller.
     *
     * @param v The vector to subtract.
     */
    void sub(const Vec2D& v);

    /**
     * Scales the vector by a factor of n.
     *
     * @param n The scaling factor.
     */
    void scale(const float n);

    /**
     * Rotates the vector by an angle in degrees and returns a new vector.
     *
     * @param angle The angle to rotate by in degrees.
     * @return A new vector that is the result of rotating the caller by the given angle.
     */
    Vec2D rotate(const float angle) const;

    /**
     * Computes the magnitude of the vector.
     *
     * @return The magnitude of the vector.
     */
    float magnitude() const;

    /**
     * Computes the squared magnitude of the vector.
     *
     * @return The squared magnitude of the vector.
     */
    float magnitudeSquared() const;

    /**
     * Computes the angle of the vector in degrees.
     *
     * @return The angle of the vector in degrees.
     */
    float angle() const;

    /**
     * Creates a new vector given the module and the angle.
     * 
     * @param module The module of the vector to create.
     * @param angle The angle (in degrees) of the vector to create.
     * @return A new vector with the specified module and angle.
    */
    static Vec2D fromModuleAngle(float module, float angle);

    /**
     * Normalizes the calling vector (changes its magnitude to 1 preserving its direction)
     *
     * @return A reference to the calling Vec2D struct after it has been normalized.
     */
    Vec2D& normalize();

    /**
     * Computes a normalized vector of the caller.
     *
     * @return A new vector that is the normalized version of the caller.
     */
    Vec2D unitVector() const;

    /**
     * Finds a clockwise perpendicular vector to the caller.
     *
     * @return A new vector that is normal(clockwise) to the caller.
     */
    Vec2D normalClockwise() const;

    /**
     * Finds a counterclockwise perpendicular vector to the caller.
     *
     * @return A new vector that is normal(counterclockwise) to the caller.
     */
    Vec2D normalCounterclockwise() const;

    /**
     * Computes the dot product of the caller with a given vector.
     *
     * @param v The vector to compute the dot product with.
     * @return The dot product of the caller and the given vector.
     */
    float dotProduct(const Vec2D& v) const;

    /**
     * Computes the cross product of the caller with a given vector.
     *
     * @param v The vector to compute the cross product with.
     * @return The cross product of the caller and the given vector.
     */
    float crossProduct(const Vec2D& v) const;

    /**
     * Linearly interpolates between a and b based on t (100% of a when t=0 and 100% of b when t=1)
     *
     * @param a The starting vector.
     * @param b The ending vector.
     * @param t The interpolation value (between 0 and 1).
     * @return A new vector that is the linear interpolation between a and b.
     */
    static Vec2D lerp(Vec2D& a, Vec2D& b, float t);

    /**
     * Overloads the assignment operator to set the components of this vector equal to those of another vector.
     *
     * @param v The vector to copy from.
     * @return A reference to this vector after the assignment has taken place.
     */
    Vec2D& operator = (const Vec2D& v);
    /**
     * Overloads the == operator to check if two Vec2D objects are equal.
     * 
     * @param v The Vec2D object to compare to.
     * @return true if the two Vec2D objects are equal, false otherwise.
     */
    bool operator == (const Vec2D& v) const;

    /**
     * Overloads the != operator to check if two Vec2D objects are not equal.
     * 
     * @param v The Vec2D object to compare to.
     * @return true if the two Vec2D objects are not equal, false otherwise.
     */
    bool operator != (const Vec2D& v) const;

    /**
     * Overloads the + operator to add two Vec2D objects.
     * 
     * @param v The Vec2D object to add.
     * @return A new Vec2D object representing the sum of the two Vec2D objects.
     */
    Vec2D operator + (const Vec2D& v) const;

    /**
     * Overloads the - operator to subtract two Vec2D objects.
     * 
     * @param v The Vec2D object to subtract.
     * @return A new Vec2D object representing the difference between the two Vec2D objects.
     */
    Vec2D operator - (const Vec2D& v) const;

    /**
     * Overloads the * operator to multiply two Vec2D objects.
     * 
     * @param v The Vec2D object to multiply.
     * @return A new Vec2D object that results from the multiplication of the two vectors.
     */
    Vec2D operator * (const Vec2D& v) const;

    /**
     * Overloads the * operator to multiply a Vec2D object by a scalar value.
     * 
     * @param scale The scalar value to multiply the Vec2D object by.
     * @return A new Vec2D object representing the scaled Vec2D object.
     */
    Vec2D operator * (const float scale) const;

    /**
     * Overloads the / operator to divide two Vec2D objects.
     * 
     * @param v The Vec2D object to divide.
     * @return A new Vec2D object that results from the division of the two vectors
     */
    Vec2D operator / (const Vec2D& v) const;

    /**
     * Overloads the - operator to negate a Vec2D object.
     * 
     * @return A new Vec2D object representing the negated Vec2D object.
     */
    Vec2D operator - ();

    /**
     * Overloads the += operator to add another Vec2D object to the current one.
     * 
     * @param v The Vec2D object to add.
     * @return A reference to the current Vec2D object after the addition.
     */
    Vec2D& operator += (const Vec2D& v);

    /**
     * Overloads the -= operator to subtract another Vec2D object from the current one.
     * 
     * @param v The Vec2D object to subtract.
     * @return A reference to the current Vec2D object after the subtraction.
     */
    Vec2D& operator -= (const Vec2D& v);

    /**
     * Overloads the *= operator to multiply the current Vec2D object element-wise by another Vec2D object.
     * 
     * @param v The Vec2D object to multiply.
     * @return A reference to the current Vec2D object after the multiplication.
     */
    Vec2D& operator *= (const Vec2D& v);

    /**
     * Divides the current vector component-wise by another vector.
     * 
     * @param v The vector to divide by.
     * @return A reference to the modified current vector.
    */
    Vec2D& operator /= (const Vec2D& v);

    /**
     * Outputs the vector components to a stream in the format "(x, y)".
     * 
     * @param os The output stream to write to.
     * @param v The vector to output.
     * @return The output stream after writing the vector.
    */
    friend std::ostream& operator<<(std::ostream &os, const Vec2D& v);
};

#endif