#include "list.hpp"
#include <iostream>
#include <ostream>

void testingList(List &list) {
    std::cout << "\nTESTING" << std::endl;
    std::cout << list << std::endl;
    
    list.insert(1, list.size());
    list.insert(2, list.size());
    list.insert(3, list.size());
    list.insert(5, list.size());
    std::cout << list << std::endl;

    std::cout << "Inserindo antes do fim" << std::endl;
    list.insert(5, list.size()-2);
    list.insert(6, list.size()-2);
    std::cout << list << std::endl;

    std::cout << "Removendo do final" << std::endl;
    list.remove(list.size()-1);
    std::cout << list << std::endl;

    std::cout << "Removendo do meio" << std::endl;
    list.remove(list.size()-3);
    std::cout << list << std::endl;

    std::cout << "Inserindo no início" << std::endl;
    list.insert(10, 0);
    std::cout << list << std::endl;

    std::cout << "Procurar por 10" << std::endl;
    bool found = list.search(10);
    std::cout << ((found == true) ? "YES" : "NO") << std::endl;

    std::cout << "Acessar o primeiro" << std::endl;
    std::cout << list.access(0) << std::endl;

    std::cout << "END TESTING" << std::endl;

}