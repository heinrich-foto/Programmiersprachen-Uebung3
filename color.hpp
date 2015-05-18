#ifndef BUW_COLOR_HPP
#define BUW_COLOR_HPP

#include <iostream>

/* Uebung 2 */

struct Color
{
    Color():r_(0),g_(0),b_(0) {}
    
    Color(double r, double g, double b) : r_((r<=1&&r>0)?r:0),
                                          g_((g<=1&&g>0)?g:0),
                                          b_((b<=1&&b>0)?b:0)
    { }
    
    
    Color(double colorValue) : r_((colorValue<=1&&colorValue>0)?colorValue:0),
                               g_((colorValue<=1&&colorValue>0)?colorValue:0),
                               b_((colorValue<=1&&colorValue>0)?colorValue:0)
    { }
    
    double r_;
    double g_;
    double b_;

    friend std::ostream& operator<<(std::ostream& os, Color const& c) 
    {
    return os << "[" << c.r_ << "; " << c.g_ << "; " << c.b_ << "]"; }
};

#endif //#define BUW_COLOR_HPP
