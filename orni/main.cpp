#include <iostream>

class Mamifero {
public:
    virtual void amamantar() = 0;
};

class Oviparo { //oviparo es un animal que pone huevos
public:
    virtual int ponerHuevos() = 0;
};

class Anfibio { //anfibio es un animal que puede respirar en el agua y fuera de ella
public:
    virtual void respirarBranquial() = 0;

    virtual void respirarPulmonar() = 0;
};

class Venenoso {
public:
    virtual void envenenar() = 0;
};

class Ornitorrinco : public Mamifero, public Oviparo, public Anfibio, public Venenoso {
protected:
    int huevos;

public:
    Ornitorrinco() { huevos = 1; }

    ~Ornitorrinco() {}

    void respirarBranquial() override {
        std::cout << "Respirando por branquias" << std::endl;
    }

    void respirarPulmonar() override {
        std::cout << "Respirando por pulmones" << std::endl;
    }

    int ponerHuevos() override {
        huevos = huevos+=1;
        return huevos;
    }

    void amamantar() override {
        std::cout << "Amamantando" << std::endl;
    }

    void envenenar() override {
        std::cout << "Envenenando" << std::endl;
    }
};

int main() {
    Ornitorrinco *perry = new Ornitorrinco();
    perry->respirarBranquial();
    perry->envenenar();
    std::cout << "He puesto: " << perry->ponerHuevos() <<" huevitos"<< std::endl;
    std::cout << "He puesto: " << perry->ponerHuevos() <<" huevitos"<< std::endl;

    return 0;
}
