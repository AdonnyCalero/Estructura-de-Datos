#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

//g++ -o main.exe main.cpp -lsfml-graphics -lsfml-window -lsfml-system

// Función para verificar si una casilla está dentro del tablero
bool dentroDelTablero(int fila, int col, int N) {
    return fila >= 0 && fila < N && col >= 0 && col < N;
}

int main() {
    int N;
    std::cout << "Ingrese el tamano del tablero: ";
    while (!(std::cin >> N) || N <= 0 || N > 50) {
        std::cout << "Entrada invalida. Ingrese un número entre 1 y 50: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    
    int fila, col;
    std::cout << "Ingrese la fila de la reina: ";
    while (!(std::cin >> fila) || fila < 1 || fila > N) {
        std::cout << "Fila invalida. Ingrese un numero entre 1 y " << N << ": ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    
    std::cout << "Ingrese la columna de la reina: ";
    while (!(std::cin >> col) || col < 1 || col > N) {
        std::cout << "Columna invalida. Ingrese un numero entre 1 y " << N << ": ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    fila -= 1;  
    col -= 1;
    
    sf::RenderWindow window(sf::VideoMode(600, 600), "Movimientos de la Reina");
    float cellSize = 600.0f / N;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        // Dibujar el tablero
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);
                cell.setFillColor((i + j) % 2 == 0 ? sf::Color::White : sf::Color::Black);
                window.draw(cell);
            }
        }

        // Dibujar los posibles movimientos de la reina
        sf::RectangleShape moveIndicator(sf::Vector2f(cellSize, cellSize));
        moveIndicator.setFillColor(sf::Color(0, 255, 0, 100));
        
        // Movimientos en todas las direcciones
        for (int i = 1; i < N; i++) {
            if (dentroDelTablero(fila + i, col, N)) {
                moveIndicator.setPosition(col * cellSize, (fila + i) * cellSize);
                window.draw(moveIndicator);
            }
            if (dentroDelTablero(fila - i, col, N)) {
                moveIndicator.setPosition(col * cellSize, (fila - i) * cellSize);
                window.draw(moveIndicator);
            }
            if (dentroDelTablero(fila, col + i, N)) {
                moveIndicator.setPosition((col + i) * cellSize, fila * cellSize);
                window.draw(moveIndicator);
            }
            if (dentroDelTablero(fila, col - i, N)) {
                moveIndicator.setPosition((col - i) * cellSize, fila * cellSize);
                window.draw(moveIndicator);
            }
            if (dentroDelTablero(fila + i, col + i, N)) {
                moveIndicator.setPosition((col + i) * cellSize, (fila + i) * cellSize);
                window.draw(moveIndicator);
            }
            if (dentroDelTablero(fila - i, col - i, N)) {
                moveIndicator.setPosition((col - i) * cellSize, (fila - i) * cellSize);
                window.draw(moveIndicator);
            }
            if (dentroDelTablero(fila + i, col - i, N)) {
                moveIndicator.setPosition((col - i) * cellSize, (fila + i) * cellSize);
                window.draw(moveIndicator);
            }
            if (dentroDelTablero(fila - i, col + i, N)) {
                moveIndicator.setPosition((col + i) * cellSize, (fila - i) * cellSize);
                window.draw(moveIndicator);
            }
        }

        // Dibujar la reina
        sf::CircleShape queen(cellSize / 2.5f);
        queen.setFillColor(sf::Color::Red);
        queen.setPosition(col * cellSize, fila * cellSize);
        window.draw(queen);

        window.display();
    }

    return 0;
}
