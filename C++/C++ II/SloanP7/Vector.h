// Vector.h -- Vector class 


#ifndef _VECTOR_H_
#define _VECTOR_H_
#include "stdafx.h"
#include <string>

namespace VECTOR
{
    class Vector
    {  
	public:
		// RECT for rectangular, POL for Polar modes
		enum Mode {RECT, POL};
		
    private:
        double x;          // horizontal value
        double y;          // vertical value
        double magnitude;        // length of vector
        double angle;        // direction of vector in degrees
        Mode mode;         // RECT or POL
		
    // private methods for setting values
        void CalcMagnitude();
        void CalcAngle();
        void CalcX();
        void CalcY();

    public:
       Vector();	//default constructor
		//default input parameters constructor
        Vector(double n1, double n2, Mode form = RECT);       

		//Get Methods
        double GetX() const {return x;}       // report x value
        double GetY() const {return y;}       // report y value
        double GetMagnitude() const {return magnitude;}   // report magnitude
        double GetAngle() const {return angle;}   // report angle
		std::string GetFormattedResult();

		//Set Methods				
        void SetInfo(double n1, double n2, Mode form = RECT);
        void SetPolarMode();                    // set mode to POL
        void SetRectMode();                     // set mode to RECT

		Vector operator +(Vector v2);
		Vector operator -(Vector v2);
		Vector operator *(double d);
		Vector operator -();
		
    };//end class Vector

}   // end namespace VECTOR
#endif
