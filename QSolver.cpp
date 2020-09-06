#include <iostream>
#include <cmath>

double getValue(int coeff)
{
  while (true)
  {
    double a = 0;
    std::cout << "Type coefficient " << coeff << ": ";
    std::cin >> a;

    if (std::cin.fail()||())
      {
        std::cin.clear(); 
        std::cin.ignore(32767,'\n');
        std::cout << "Input value is incorrect. Please try again.\n";
      }
      else
      {
        std::cin.ignore(32767,'\n'); 
        return a;
      }
  }
}

void solve (double coeff1, double coeff2, double coeff3)
{
  double discriminant = 0;
  double x[3] = {0, 0, 0}; // x[3] - imaginary part
  discriminant = coeff2*coeff2 - 4*coeff1*coeff3;

  if (discriminant > 0) 
  {
    x[0] = (-coeff2 + sqrt(discriminant)) / (2*coeff1);
    x[1] = (-coeff2 - sqrt(discriminant)) / (2*coeff1);
    std::cout << "Two real roots exist." << std::endl;
    std::cout << "x1 = " << x[0] << std::endl;
    std::cout << "x2 = " << x[1] << std::endl;
  }

  else if (discriminant == 0) 
  {
    std::cout << "One real root exists." << std::endl;
    x[0] = (-coeff2 + sqrt(discriminant)) / (2*coeff1);
    std::cout << "x =" << x[0] << std::endl;
  }

  else 
  {
    x[0] = -coeff2/(2*coeff1);
    x[2] =sqrt(-discriminant)/(2*coeff1);
    std::cout << "Two complex roots exist."  << std::endl;
    std::cout << "x1 = " << x[0] << "+" << x[2] << "i" << std::endl;
    std::cout << "x2 = " << x[0] << "-" << x[2] << "i" << std::endl;
  }
}

void solveLinear(double coeff2, double coeff3)
{
  double x = 0;
  x = -coeff3/coeff2;
  std::cout << "Equasion is linear. One root exists."  << std::endl;
  std::cout << "x = " << x << std::endl;
}

int main()
{
  double coeff[3] = {1, 2, 3};
  int i = 0;

  for (i = 0; i < 3; i++)
    {
      coeff[i] = getValue(coeff[i]);
    }

  if ((coeff[0] == 0)&&(coeff[1] == 0)&&(coeff[2] == 0))
  {
    std::cout << "Equasion is true for any x."  << std::endl;
    return 0;
  }

  if ((coeff[0] == 0)&&(coeff[1] == 0))
  {
    std::cout << "There is no solution for this equasion."  << std::endl;
    return 0;
  }

  if (coeff[0] == 0)
  {
    solveLinear(coeff[1], coeff[2]);
    return 0;
  }

  solve(coeff[0], coeff[1], coeff[2]);

  return 0;
}
