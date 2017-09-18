#include <string>
#include <exception>

using namespace std;

class EqualLines: public exception
{
 public:
  const char * what () const throw();
};

class ParallelLines: public exception
{
 public:
  const char * what () const throw();
};

class Line {
 public:
  Line(double slope, double y_intercept): a(slope), b(y_intercept) {};
  double intersect(const Line L) const;
  
 private:
  double a;
  double b;
};


