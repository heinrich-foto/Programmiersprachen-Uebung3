#ifndef BUW_POINT2D_HPP
#define BUW_POINT2D_HPP

#include "color.hpp"
//#include "window.hpp"
// Include Guard verhinder Mehrfachincludierung. Wenn bereits irgendwo includiert
// muss und darf nicht erneut definiert werden.
// deshalb - if_not_defined - dann definiere diese Klassen Definitionen... (pendet zu ifdef)
// [Bedingte Kompilierung]

// Point2d class declaration

class Window;
class Point2D {
public:
    Point2D();										// Standart Konstruktor
    Point2D(double const& x, double const& y);		// ?Default Konsttruktor
    Point2D(double const& x, double const& y, Color const& color);
    ~Point2D();										// Destruktor - wird beim zerstören des Objektes aufgerufen.
    // Ist somit letzte Aktion (letztes Lebenszeichen)
    // kann zum aufräumen verwendet werden. Sicherung von Daten etc.
    
    void x(double const& x);
    void y(double const& y);
    double x() const;
    double y() const;
    
    // void draw(Window & win) const;
    
    Point2D Point() const;							// liefert Punkt?
    
    void color(Color const& colorValue);			// Setzt Farbe
    Color color() const;							// Gibt Farbe zurück
    
    void translate(double const& x_transition, double const& y_transition);
    void rotate(double const& radiant);
    void rotate(double const& radiant, Point2D const& center);
    void rotate(double const& radiant, Point2D const& center, bool filled);
    // void rotate(double const& radiant, Point2D const& point);
    // void rotate2(double const& radient, Point2D const& point);
    friend std::ostream& operator<<(std::ostream& os, Point2D const& c);
private:
    double		x_;
    double		y_;
    Color 	color_;
};


// Punkte nicht addieren.
//affiner Raum

#endif // BUW_POINT2D_HPP