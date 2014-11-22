//Vector.cpp -- methods for the Vector class
#include "stdafx.h"
#include <cmath>
#include <string>
#include <sstream>
#include "Vector.h"// includes <iostream>

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;	//arc tangent given one value
using std::atan2;	//arc tangent given two values, computes quadrant
using std::string;
using std::stringstream;

namespace VECTOR
{
    // compute degrees in one radian
    const double Rad_to_deg = 45.0 / atan(1.0);
    // should be about 57.2957795130823

    // private methods
    // calculates magnitude from x and y
    void Vector::CalcMagnitude()
    {
        magnitude = sqrt(x * x + y * y);
    }

    void Vector::CalcAngle()
    {
        if (x == 0.0 && y == 0.0)
            angle = 0.0;
        else
            angle = atan2(y, x);
    }

    // set x from polar coordinate
    void Vector::CalcX()
    {
        x = magnitude * cos(angle);
    }

    // set y from polar coordinate
    void Vector::CalcY()
    {
        y = magnitude * sin(angle);
    }

    // public methods
    Vector::Vector()             // default constructor
    {
        x = y = magnitude = angle = 0.0;
        mode = RECT;
		
    }

    // construct vector from rectangular coordinates if form is r
    // (the default) or else from polar coordinates if form is p
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
         {
             x = n1;
             y = n2;
             CalcMagnitude();
             CalcAngle();
        }
        else if (form == POL)
        {
             magnitude = n1;
             angle = n2 / Rad_to_deg;
             CalcX();
             CalcY();
        }

    }

    // reset vector from rectangular coordinates if form is
    // RECT (the default) or else from polar coordinates if
    // form is POL
    void Vector:: SetInfo(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
         {
             x = n1;
             y = n2;
             CalcMagnitude();
             CalcAngle();
        }
        else if (form == POL)
        {
             magnitude = n1;
             angle = n2 / Rad_to_deg;
             CalcX();
             CalcY();
        }
    }

    void Vector::SetPolarMode()    // set to polar mode
    {
        mode = POL;
    }

    void Vector::SetRectMode()     // set to rectangular mode
    {
        mode = RECT;
    }

    // display rectangular coordinates if mode is RECT,
    // else display polar coordinates if mode is POL
    string Vector::GetFormattedResult()
    {
		stringstream ss;
        if (mode == Vector::RECT)
             ss << "(x,y components) = (" << x << ", " << y << ")";
        else if (mode == Vector::POL)
        {
             ss << "(magnitude,angle) = (" << magnitude << ", "
                 << angle * Rad_to_deg << ")";
        }

        return ss.str(); 
    }

	Vector Vector::operator +(Vector v2)
	{	Vector v3;
		x = x + v2.x;
		y = y + v2.y;
		CalcMagnitude();
		CalcAngle();
		return v3;
		
	}

	Vector Vector::operator -(Vector v2)
	{	Vector v3;
		x = x - v2.x;
		y = y - v2.y;
		CalcMagnitude();
		CalcAngle();
		return v3;
	}
	
	Vector Vector::operator *(double d)
	{	Vector v3;
		x = x * d;
		y = y * d;
		CalcMagnitude();
		CalcAngle();
		return v3;
	}

	Vector Vector::operator -()
	{	Vector v3;
		x = x * -1;
		y = y * -1;
		CalcMagnitude();
		CalcAngle();
		return v3;
	}
}  // end namespace VECTOR
