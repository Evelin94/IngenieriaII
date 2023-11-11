#include <iostream>
#include <vector>

// Clase base abstracta que representa una forma.
class Shape {
public:
    virtual void Draw() const = 0;
    virtual ~Shape() = default;
};

// Clase derivada  representa un cuadrado.
class Square : public Shape {
public:
    void Draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }
};


class Circle : public Shape {
public:
    void Draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

// Función para dibujar todas las formas sin modificarlas para nuevas formas.
void DrawAllShapes(const std::vector<Shape*>& shapes) {
    for (const auto& shape : shapes) {
        shape->Draw();
    }
}

int main() {
    
    Square square;
    Circle circle;

    
    std::vector<Shape*> shapes = {&square, &circle};

    DrawAllShapes(shapes);

    return 0;
}
