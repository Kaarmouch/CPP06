#include "Base.hpp"
Base::~Base(void){std::cout <<"Destroyer" << std::endl;}

Base* generate(void) {
    std::srand(std::time(0));
    int r = std::rand() % 3;
    std::cout << r << std::endl;
    switch (r) {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
    }
    return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& r) {
    try {
        (void)dynamic_cast<A&>(r);
        std::cout << "A" << std::endl;
    } catch (...) {
        try {
            (void)dynamic_cast<B&>(r);
            std::cout << "B" << std::endl;
        } catch (...) {
            try {
                (void)dynamic_cast<C&>(r);
                std::cout << "C" << std::endl;
            } catch (...) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}
