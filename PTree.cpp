// "Copyright [2023] <Truong-Thinh Huynh>"

#include <vector>
#include <iostream>
#include <cmath>

#include "PTree.hpp"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

PTree::PTree() {
  length = 0;
  depth = 0;
  angle = 0;
  isExtraCredit = false;
  r = 0;
  g = 0;
  b = 0;
}

PTree::~PTree() {}

void PTree::setLength(double inLength) {
  length = inLength;
}

void PTree::setDepth(int inDepth) {
  depth = inDepth;
}

void PTree::setAngle(int inAngle) {
  angle = inAngle;
}

void PTree::setVecSquare(sf::RectangleShape inSquare) {
  vecSquare.push_back(inSquare);
}

void PTree::setIsExtraCredit(bool inIsExtraCredit) {
  isExtraCredit = inIsExtraCredit;
}

void PTree::setVecColor(sf::Color inColor) {
  vecColor.push_back(inColor);
}

void PTree::setRGB(sf::Color inColor) {
  r = inColor.r;
  g = inColor.g;
  b = inColor.b;
}

double PTree::getLength() const {
  return length;
}

int PTree::getDepth() const {
  return depth;
}

int PTree::getAngle() const {
  return angle;
}

std::vector<sf::RectangleShape> PTree::getVecSquare() const {
  return vecSquare;
}

bool PTree::getIsExtraCredit() const {
  return isExtraCredit;
}

std::vector<sf::Color> PTree::getVecColor() const {
  return vecColor;
}

sf::Color PTree::getRGB() const {
  sf::Color colorTemp;
  colorTemp.r = r;
  colorTemp.g = g;
  colorTemp.b = b;

  return colorTemp;
}

void PTree::clearVecSquare() {
  vecSquare.clear();
}

void PTree::clearVecColor() {
  vecColor.clear();
}

void PTree::pTree(sf::RectangleShape inPS, double inL, int inD, int inA) {
  if (inD < 1) {
    return;
  }

  if (isExtraCredit == true) {
    // Set size
    double lCRadians = std::abs(angle) * M_PI / 180;
    double lCSide = inL * cos(lCRadians);

    sf::RectangleShape lCS;
    lCS.setSize(sf::Vector2f(lCSide, lCSide));
    lCS.setOrigin(sf::Vector2f(0.f, lCS.getSize().y));

    // Get coord at top left of parent square
    sf::Vector2f lCSTemp = sf::Vector2f(0.f, 0.f);

    sf::Vector2f inPSPos = inPS.getTransform().transformPoint(lCSTemp);
    // Use parent top left coord to rotate left
    lCS.setPosition(inPSPos.x, inPSPos.y);

    int lCAngle = inA;
    lCS.rotate(lCAngle);

    r = (r + 10) % 360;
    g = (g + 40) % 360;
    b = (b + 100) % 360;

    // Set color based on depth but skip 0 because it is for parent
    lCS.setFillColor(vecColor.at((depth - inD) + 1));

    this->setVecSquare(lCS);
    this->pTree(lCS, lCSide, inD - 1, lCAngle - angle);

    // Set size
    double rCRadians = std::abs(angle) * M_PI / 180;
    double rCSide = inL * sin(rCRadians);

    sf::RectangleShape rCS;

    rCS.setSize(sf::Vector2f(rCSide, rCSide));
    rCS.setOrigin(sf::Vector2f(0.f, rCS.getSize().y));

    // Get coord at top of bottom right of left child square
    sf::Vector2f rCSTemp = sf::Vector2f(lCS.getSize().x, lCS.getSize().y);

    sf::Vector2f lChildPos = lCS.getTransform().transformPoint(rCSTemp);

    // Use left child bottom right coord to rotate right
    rCS.setPosition(lChildPos.x, lChildPos.y);

    int rCAngle = 90 + inA;
    rCS.rotate(rCAngle);

    rCS.setFillColor(vecColor.at((depth - inD) + 1));

    this->setVecSquare(rCS);
    this->pTree(rCS, rCSide, inD - 1, lCAngle + (90 - angle));

    // Same concept from above but without the color change
  } else {
    double lCRadians = std::abs(angle) * M_PI / 180;
    double lCSide = inL * cos(lCRadians);

    sf::RectangleShape lCS;
    lCS.setSize(sf::Vector2f(lCSide, lCSide));
    lCS.setOrigin(sf::Vector2f(0.f, lCS.getSize().y));

    sf::Vector2f inPSPos = inPS.getTransform().transformPoint(sf::Vector2f(0.f, 0.f));
    lCS.setPosition(inPSPos.x, inPSPos.y);

    int lCAngle = inA;
    lCS.rotate(lCAngle);

    this->setVecSquare(lCS);
    this->pTree(lCS, lCSide, inD - 1, lCAngle - 45);

    double rCRadians = std::abs(angle) * M_PI / 180;
    double rCSide = inL * sin(rCRadians);

    sf::RectangleShape rCS;

    rCS.setSize(sf::Vector2f(rCSide, rCSide));
    rCS.setOrigin(sf::Vector2f(0.f, rCS.getSize().y));

    sf::Vector2f lCSTemp = sf::Vector2f(lCS.getSize().x, lCS.getSize().y);

    sf::Vector2f lChildPos = lCS.getTransform().transformPoint(lCSTemp);

    rCS.setPosition(lChildPos.x, lChildPos.y);

    int rCAngle = 90 + inA;
    rCS.rotate(rCAngle);

    this->setVecSquare(rCS);
    this->pTree(rCS, rCSide, inD - 1, lCAngle + 45);
  }
}

void PTree::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  // Draw rectangle shape
  for (size_t i = 0; i < vecSquare.size(); i++) {
    target.draw(vecSquare.at(i));
  }
}
