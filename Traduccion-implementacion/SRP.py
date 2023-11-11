class Rectangulo:
    def __init__(self, ancho, alto):
        self.ancho = ancho
        self.alto = alto

class DibujadorRectangulo:
    def draw(self, rectangulo):
        print(f"Dibujando rectángulo de ancho {rectangulo.ancho} y alto {rectangulo.alto}")

class CalculadoraArea:
    def area(self, rectangulo):
        return rectangulo.ancho * rectangulo.alto

# Ejemplo de uso con las nuevas clases
mi_rectangulo = Rectangulo(5, 10)
dibujador = DibujadorRectangulo()
calculadora = CalculadoraArea()

dibujador.draw(mi_rectangulo)  # Dibujar el rectángulo en la pantalla
print("Área del rectángulo:", calculadora.area(mi_rectangulo))  # Calcular y mostrar el área
