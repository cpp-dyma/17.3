#include <iostream>

template <typename T, int taille>
class Tableau
{
private:
    int m_length{};
    T* m_data{};

public:

    Tableau();

    ~Tableau();

    void erase();

    T& operator[](int index);

    int getLength() const;

    void afficher();
};

template<typename T, int taille> 
Tableau<T, taille>::Tableau(){
    m_data = new T[taille]{};
    m_length = taille;
}

template<typename T, int taille> 
Tableau<T, taille>::~Tableau(){
    delete[] m_data;
}

template<typename T, int taille> 
void Tableau<T, taille>::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

template<typename T, int taille> 
int Tableau<T, taille>::getLength() const {
    return m_length;
}

template<typename T, int taille> 
void Tableau<T, taille>::afficher() 
{
    for(int i{0} ; i<this->getLength(); i++){
        std::cout<<m_data[i]<<" ";
    }
}

template <typename T, int taille>
T& Tableau<T, taille>::operator[](int index)
{
    if(index < 0 || index >= m_length){
        throw std::overflow_error("Error");
    }
    return m_data[index];
}

