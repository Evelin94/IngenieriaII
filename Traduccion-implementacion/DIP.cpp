#include <iostream>

// Abstraction representing the high-level policy
class ButtonClient {
public:
    virtual void TurnOn() = 0;
    virtual void TurnOff() = 0;
    virtual ~ButtonClient() = default; 
};

class Lamp : public ButtonClient {
public:
    void TurnOn() override {
        std::cout << "Lamp turned on.\n";
    }

    void TurnOff() override {
        std::cout << "Lamp turned off.\n";
    }
};

// abstraccion
class Button {
public:
    Button(ButtonClient& client) : itsClient(&client) {}

    void Detect() {
        bool buttonOn = GetState();
        if (buttonOn)
            itsClient->TurnOn();
        else
            itsClient->TurnOff();
    }

    virtual bool GetState() = 0;
    virtual ~Button() = default;  

private:
    ButtonClient* itsClient;
};

// completa implementacion 
class PhysicalButton : public Button {
public:
    PhysicalButton(ButtonClient& client) : Button(client) {}

    bool GetState() override {
        return 0;
    }
};

int main() {
    // Crea a Lamp y  PhysicalButton
    Lamp lamp;
    PhysicalButton button(lamp);

    // Simula button 
    button.Detect();

    return 0;
}
