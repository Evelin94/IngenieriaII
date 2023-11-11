#include <iostream>

// Interfaz base para Set y PersistentSet
template <class T>
class SetInterface {
public:
    virtual void Add(const T& t) = 0;
    virtual bool IsMember(const T& t) const = 0;
    // Agrega otras funciones comunes necesarias
    virtual ~SetInterface() {}
};

// Implementación básica de Set
template <class T>
class Set : public SetInterface<T> {
public:
    void Add(const T& t) override {
        // Implementación de Add para Set
        std::cout << "Adding to Set" << std::endl;
    }

    bool IsMember(const T& t) const override {
        // Implementación de IsMember para Set
        std::cout << "Checking membership in Set" << std::endl;
        return false;
    }
   
};

// Implementación básica de PersistentObject
class PersistentObject {
  
};

// Implementación de PersistentSet
template <class T>
class PersistentSet : public SetInterface<T> {
private:
    Set<PersistentObject> itsThirdPartyPersistentSet;

public:
    void Add(const T& t) override {
        // solo se pueda agregar un objeto derivado de PersistentObject
        static_assert(std::is_base_of<PersistentObject, T>::value, "T must be derived from PersistentObject");
        itsThirdPartyPersistentSet.Add(static_cast<PersistentObject>(t));
    }

    bool IsMember(const T& t) const override {
        // Implementación de IsMember para PersistentSet
        std::cout << "Checking membership in PersistentSet" << std::endl;
        return false;
    }
    
};

int main() {
    Set<int> mySet;
    PersistentSet<PersistentObject> myPersistentSet;

    mySet.Add(42);
    myPersistentSet.Add(PersistentObject());

    return 0;
}
