#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

template <typename T>
class Tableau
{
private:
    int m_length{};
    T* m_data{};

public:

    TableauEntier(int length)
    {
        m_data = new T[length]{};
        m_length = length;
    }

    ~TableauEntier()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    T& operator[](int index);

    int getLength() const { return m_length; }

    void afficher()
    {
        for(int i{0} ; i<this->getLength(); i++){
            std::cout<<m_data[i]<<" ";
        }
    }
};

template <typename T>
T& Tableau<T>::operator[](int index)
{
    if(index < 0 || index >= m_length){
        throw std::overflow_error("Error");
    }
    return m_data[index];
}

int main(){

    const int taille {5};
    Tableau<int> t{taille};

    for(int i{0} ; i<taille ; i++){
        t[i] = i*2;
    }

    t.afficher();

    return 0;
}

