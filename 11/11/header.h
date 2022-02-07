#ifndef HEADER_H
#define HEADER_H

struct point {
  double x, y;
};

struct rec {
  struct point p1, p2, p3;
};

struct rec *createRec( void );
double Perim( const struct rec *r );
double Square( const struct rec *r );

#endif


