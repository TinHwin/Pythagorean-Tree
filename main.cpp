// "Copyright [2023] <Truong-Thinh Huynh>"

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "PTree.hpp"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
  PTree pTree;

  // Determine if the tree is default or extra credit
  if (argc == 3) {
    pTree.setLength(atof(argv[1]));
    pTree.setDepth(atoi(argv[2]));
    pTree.setAngle(45);
    pTree.setIsExtraCredit(false);
  } else if (argc == 4) {
    pTree.setLength(atof(argv[1]));
    pTree.setDepth(atoi(argv[2]));
    pTree.setAngle(atoi(argv[3]));
    pTree.setIsExtraCredit(true);
  } else {
    std::cout << "Invalid command-line arguments." << std::endl;
  }

  // Set the window size with x being 6 * L and y being 4 * L
  sf::RenderWindow window(sf::VideoMode(6 * pTree.getLength(), 4 * pTree.getLength()), "");

  sf::RectangleShape pS;
  pS.setSize(sf::Vector2f(pTree.getLength(), pTree.getLength()));

  // Set origin at top left because left child will be position on it
  pS.setOrigin(sf::Vector2f(0.f, 0.f));

  // Center the base square at the middle and at the bottom
  double pSLHS = (window.getSize().x / 2) - (pS.getSize().x / 2);
  double pSRHS = window.getSize().y - pS.getSize().y;

  pS.setPosition(pSLHS, pSRHS);

  int r = 45;
  int g = 73;
  int b = 35;

  sf::Color color;

  // Set range of color based on depth
  for (int i = 0; i < (pTree.getDepth() + 1); i++) {
    color.r = r;
    color.g = g;
    color.b = b;

    pTree.setVecColor(color);

    r = (r + 10) % 360;
    g = (g + 40) % 360;
    b = (b + 100) % 360;
  }

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();

    std::vector<sf::Color> tempVecColor;
    sf::Color tempColor;

    // Move color by 1 so it is like a gradiant
    for (size_t i = 0; i < (pTree.getVecColor().size() - 1); i++) {
      tempVecColor.push_back(pTree.getVecColor().at(i + 1));
    }

    tempVecColor.push_back(pTree.getVecColor().at(0));

    pTree.clearVecColor();

    for (size_t i = 0; i < tempVecColor.size(); i++) {
      tempColor = tempVecColor.at(i);

      pTree.setVecColor(tempColor);
    }

    tempVecColor.clear();

    if (pTree.getIsExtraCredit() == true) {
      pS.setFillColor(pTree.getVecColor().at(0));
    }

    pTree.setVecSquare(pS);

    if (pTree.getIsExtraCredit() == true) {
      pS.setFillColor(pTree.getVecColor().at(0));
    }

    if (pTree.getIsExtraCredit() == true) {
      pTree.pTree(pS, pTree.getLength(), pTree.getDepth(), -pTree.getAngle());
    } else {
      pTree.pTree(pS, pTree.getLength(), pTree.getDepth(), -pTree.getAngle());
    }

    window.draw(pTree);
    window.display();

    pTree.clearVecSquare();
    pTree.setVecSquare(pS);
  }

  return 0;
}
