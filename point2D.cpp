#include "point2D.hpp"
#include <iostream>
#include <cmath>

Point2D::Point2D() : x_(0), y_(0), color_() {}

Point2D::~Point2D() {							// Destruktor mit Ausgabe auf dem OS Stream.
    //std::cout << "Point destroyed <-- (" <<
    //x_ << ", " << y_ << ")" << std::endl;
}

Point2D::Point2D(double const& x, double const& y)
: x_(x), y_(y), color_{} { }

Point2D::Point2D(double const& x, double const& y, Color const& color)
: x_(x), y_(y), color_(color) { }

double Point2D::x() const {
    return x_;
}
double Point2D::y() const {
    return y_;
}

void Point2D::color(Color const& colorValue)
{
    color_ = colorValue;
}

Color Point2D::color() const
{
    return color_;
}

// void Point2D::draw(Window & win) const
// {
//     win.drawPoint(x_, y_, color_.r_, color_.g_, color_.b_);
// }
void Point2D::translate(double const& x_transition, double const& y_transition)
{
    x_ += x_transition;
    y_ += y_transition;
}

void Point2D::rotate(double const& radiant)
/* Eine Methode rotate(double) rotiert den Punkt im Uhrzeigersinn um den
 Punkt (0,0). Der Rotationswinkel wird im Bogenmaß angegeben. */
{	auto radiant_ = fmod(radiant,2*M_PI);
    auto x = x_;
    auto y = y_;
    
    x_ = (x*cos(radiant_))-(y*sin(radiant_));
    y_ = (x*sin(radiant_))+(y*cos(radiant_));
}
void Point2D::rotate(double const& radiant, Point2D const& center)
{
    rotate(radiant, center, false);
}

void Point2D::rotate(double const& radiant, Point2D const& center, bool filled)
/* Bool Filled = true führt zu ausgeülltem Kreis. sollte viellcht in Klasse Kreis überladen werden?
 Oder eine adapter Klasse shape eingeführt werden.
 Diese benötigt diese Art der Drehung für die Darstellung. Derzeit.
 Ansonsten wird nur die Kontur gemalt. */
{ double x,y = 0;
    if ( !filled ) {
        x = -center.x()+x_;
        y = -center.y()+y_;
    } else {
        x = center.x()-x_;
        y = center.y()-y_;
    }
    Point2D r{x,y};
    r.rotate(radiant);
    x_ = r.x() + center.x();
    y_ = r.y() + center.y();
}


std::ostream& operator<<(std::ostream& os, Point2D const& c)
{
    return os << "("<< c.x()
			 << "; "<< c.y() << ")" <<
			 " color: " << c.color() ; }