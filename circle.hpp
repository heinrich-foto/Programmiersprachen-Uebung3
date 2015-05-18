#ifndef BUW_CIRCLE_HPP
#define BUW_CIRCLE_HPP

#include <iostream>
#include "point2D.hpp"
#include "color.hpp"
//#include "window.hpp"
class Window;
/* Uebung 2 */
class Circle {
public:
    Circle();										// Standart Konstruktor
    Circle(Point2D const& center);
    Circle(Point2D const& center, double const& radius);
    ~Circle();										// Destruktor
    
    void center(Point2D const& centerPoint);
    Point2D center() const;
    
    double radius() const;
    void radius(double const& radius);
    
    // void draw(Window & win) const;
    // void draw(Window & win, Color const& color) const;
    // void draw(Window & win, Color const& color, int const& segment) const;
    // void draw(Window & win, int const& segment) const ;
    // void draw_full(Window & win) const;
    
    void color(Color const& colorValue);			// Setzt Farbe
    Color color() const;							// Gibt Farbe zurück
    
    void translate(double const& x_transition, double const& y_transition);
    
    float area() const;
    void area(double const& area_value); 					// verändert den Radius über die Fläche
    
    float circumference() const;
    void circumference(double const& circumference_value);
    
    bool is_inside(Point2D const& point) const ;

    // friend bool operator<(Circle const& lhs, Circle const& rhs);
    // friend bool operator>(Circle const& lhs, Circle const& rhs);
    // friend bool operator==(Circle const& lhs, Circle const& rhs);
    friend bool operator<(Circle const& lhs, Circle const& rhs );
    friend bool operator>(Circle const& lhs, Circle const& rhs );
    friend bool operator==(Circle const& lhs, Circle const& rhs );
    friend std::ostream& operator<<(std::ostream& os, Circle const& c);

private:
    Color 		color_;
    Point2D 		center_;
    double			radius_;
};

#endif // BUW_CIRCLE_HPP