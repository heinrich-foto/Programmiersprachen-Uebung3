#include "circle.hpp"
#include "point2D.hpp"
#include "color.hpp"
#include <cmath>

/* Uebung 2 */
/* Membervariablen.
	Color 		color_;
	Point2D 		center_;
	double			radius_; */

Circle::Circle() :
color_{},
center_{Point2D(0.0,0.0)},
radius_(0.1)
{
    //center_.color(color_);
}

Circle::Circle(Point2D const& centerPoint):
color_{Color(0,0,0)},
center_{centerPoint},
radius_(0.1)
{
    color_ = center_.color();
}
Circle::Circle(Point2D const& centerPoint, double const& radius):
color_{Color(0,0,0)},
center_{centerPoint},
radius_(radius)
{
    color_ = center_.color();
}
Circle::~Circle() {
    //std::cout << "Circle destroyed <-- " <<
    //center_ << " radius " << radius_ << std::endl;
}

void Circle::center(Point2D const& center)
{
    center_ = center;
}
Point2D Circle::center() const
{
    return center_;
}

double Circle::radius() const
{
    return radius_;
}
void Circle::radius(double const& radius)
{
    if (radius >=0) radius_ = radius;
}

// void Circle::draw(Window &win) const
// {
//     this->draw(win,360);
// }

// void Circle::draw(Window & win, Color const& color, int const& segment) const
// {
//     Point2D point{(center_.x()+radius_),(center_.y()),color};
//     Point2D point2=point;
//     point.rotate((2*M_PI)/segment,center_);
//     for (int i = 0; i<=segment; ++i)
//     {
//         win.drawLine(point2.x(),point2.y(),point.x(),point.y(),color.r_,color.g_,color.b_);
//         point.rotate((2*M_PI)/segment,center_);
//         point2.rotate((2*M_PI)/segment,center_);
//     }
// }
// void Circle::draw(Window & win, int const& segment) const
// {
//     this->draw(win,color_,segment);
// }

// void Circle::draw(Window & win, Color const& color) const
// {
//     this->draw(win,color,360);
// }
// void Circle::draw_full(Window & win) const
// {
//     int segment = 360;
//     Point2D point{(center_.x()+radius_),(center_.y()),color_};
//     Point2D point2=point;
//     point.rotate((2*M_PI)/segment,center_, true);
//     for (int i = 0; i<=segment; ++i)
//     {
//         win.drawLine(point2.x(),point2.y(),point.x(),point.y(),color_.r_,color_.g_,color_.b_);
//         point.rotate((2*M_PI)/segment,center_, true);
//         point2.rotate((2*M_PI)/segment,center_, true);
//     }
// }

void Circle::color(Color const& colorValue)
{
    color_ = colorValue;
}

Color Circle::color() const
{
    return color_;
}

void Circle::translate(double const& x_transition, double const& y_transition)
{
    center_.translate(x_transition,y_transition);
}

float Circle::area() const
{
    return M_PI * pow(radius_,2);
}

void Circle::area(double const& area_value)
{
    if (area_value >= 0) radius_ = sqrt(area_value / M_PI);
}


float Circle::circumference() const
{
    return 2* radius_ * M_PI;
}

void Circle::circumference(double const& circumference_value)
{
    if (circumference_value >= 0) radius_ = circumference_value / (2*M_PI);
}

bool Circle::is_inside(Point2D const& point) const
{
    return (sqrt(pow(center_.x()-point.x(),2) + pow(center_.y()-point.y(),2)) <= radius_);
}


// bool operator<(Circle const& lhs, Circle const& rhs) 
//   {
//      return (lhs.radius() < rhs.radius());
//   }

// bool operator>(Circle const& lhs, Circle const& rhs) 
//   {
//      return (lhs.radius() > rhs.radius());
//   }

bool operator<(Circle const& lhs, Circle const& rhs) 
  {
    return (lhs.radius() < rhs.radius());
  }

bool operator>(Circle const& lhs, Circle const& rhs) 
  {
    return (lhs.radius() > rhs.radius());
  }
bool operator==(Circle const& lhs, Circle const& rhs) 
  { // nur radius gemäß aufgabe? weil ist ja eigentlich nicht gleich.
    return (lhs.radius() == rhs.radius());
  }
  
std::ostream& operator<<(std::ostream& os, Circle const& c) 
  {
    return os << "radius = " << c.radius() <<
             " " << c.center() ; }