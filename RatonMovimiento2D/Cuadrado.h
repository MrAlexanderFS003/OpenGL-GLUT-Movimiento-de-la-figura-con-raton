class Cuadrado {
	float posX = 0.0f, posY = 0.0f;
public:
	Cuadrado(){} // Constructor Predeterminado
	void Dibuja();
	void Actualiza();

	//Getters y Setters
	void setPosX(float valor) { posX = valor; }
	void setPosY(float valor) { posY = valor; }

	float getPosX() { return posX; }
	float getPosY() { return posY; }
};