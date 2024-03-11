// "Copyright [2023] <Truong-Thinh Huynh>"

#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#pragma once

class PTree: public sf::Drawable {
 public:
  PTree();
  virtual ~PTree();

  // Setters
  void setLength(double);
  void setDepth(int);
  void setAngle(int);
  void setVecSquare(sf::RectangleShape);
  void setIsExtraCredit(bool inIsExtraCredit);
  void setVecColor(sf::Color);
  void setRGB(sf::Color);

  // Getters
  double getLength() const;
  int getDepth() const;
  int getAngle() const;
  std::vector<sf::RectangleShape> getVecSquare() const;
  bool getIsExtraCredit() const;
  std::vector<sf::Color> getVecColor() const;

  sf::Color getRGB() const;

  void clearVecSquare();
  void clearVecColor();

  void pTree(sf::RectangleShape, double, int, int);

 private:
  double length;
  int depth;
  int angle;
  std::vector<sf::RectangleShape> vecSquare;
  bool isExtraCredit;
  std::vector<sf::Color> vecColor;

  int r;
  int g;
  int b;

  virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};
