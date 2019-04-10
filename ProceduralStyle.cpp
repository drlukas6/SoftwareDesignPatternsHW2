//
// Created by Lukas Sestic on 2019-04-09.
//

#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <vector>

struct Point {
    int x;
    int y;
};

class Shape {
public:
    Point center;
    virtual void draw() =0;
};

class Circle: public Shape {
public:
    double radius;
    virtual void draw() {
        std::cout << "Drawing a circle at " << this->center.x << " " << this->center.y << "\n";
    }
};

class Square: public Shape {
public:
    double side;
    virtual void draw() {
        std::cout << "Drawing a square at " << this->center.x << " " << this->center.y << "\n";
    }
};

void drawShapes(std::vector<Shape *>  &shapes) {
    for (auto &shape: shapes) {
        shape->draw();
    }
}

void moveShapes(std::vector<Shape *> &shapes, int deltaX, int deltaY) {
    for (auto &shape: shapes) {
        shape->center.x += deltaX;
        shape->center.y += deltaY;
        shape->draw();
    }
}


int main(){
    std::vector<Shape *> shapes;

    Circle *circle1 = new Circle();
    circle1->center = {1, 1};
    circle1->radius = 3.14;
    Square *square1 = new Square();
    square1->center = {2, 5};
    square1->side = 32.5;
    Square *square2 = new Square();
    square2->center = {5, 1};
    square2->side = 3.5;
    Circle *circle2 = new Circle();
    circle2->center = {3, 3};
    circle2->radius = 44.5;

    shapes.emplace_back(circle1);
    shapes.emplace_back(circle2);
    shapes.emplace_back(square1);
    shapes.emplace_back(square2);
    drawShapes(shapes);

    std::cout << "------------------------\n";

    moveShapes(shapes, 2, 5);

    return 0;
}