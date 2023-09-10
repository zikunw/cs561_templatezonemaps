#include "zonemaps.h"
#include <iostream>

template<typename T>
zonemap<T>::zonemap(std::vector<T> _elements, uint _num_elements_per_zone)
{
    // constructor
    elements = _elements;
    num_elements_per_zone = _num_elements_per_zone;
    num_zones = std::ceil(elements.size() / num_elements_per_zone) ;

    this->build();
    //this->print();
}

template<typename T>
void zonemap<T>::build()
{
    // construct zones
    for (int i=0; i<this->num_zones; i++) {
        zone<T> z;
        z.min = this->elements[i * this->num_elements_per_zone];
        z.max = this->elements[i * this->num_elements_per_zone];
        z.size = 0;
        for (int j=0; j<this->num_elements_per_zone; j++){
            int index = i * this->num_elements_per_zone + j;
            if (index < this->elements.size()) {
                z.size += 1;
                z.elements.push_back(this->elements[index]);

                if (this->elements[index] < z.min)
                    z.min = this->elements[index];

                if (this-> elements[index] > z.max)
                    z.max = this->elements[index];
            }
        }

        // append to the zonemap
        this->zones.push_back(z);
    }
}

template<typename T>
bool zonemap<T>::query(T key)
{
    // Try to find zone that include the key
    for (auto const &z : this->zones) {
        if (key >= z.min && key <= z.max) {
            // scan within the block
            for (auto &e : z.elements){
                if (e == key) {
                    return true;
                }
            }
        }
    }
    return false;
}


template<typename T>
std::vector<T> zonemap<T>::query(T low, T high) {
    std::vector<T> queryResult;

    for (auto const &z : this->zones) {
        if (!(low > z.max) || !(high < z.min)) {
            for (auto e : z.elements) {
                if (e >= low && e <= high) {
                    queryResult.push_back(e);
                }
            }
        }
    }

    return queryResult;
}


// for debugging purpose
template<typename T>
void zonemap<T>::print()
{
    // zonemap
    std::cout << "num_elements_per_zone: " << this->num_elements_per_zone << "; num_zones: " << this->num_zones << std::endl;

    // zones
    for (auto zone : this->zones) {
        std::cout << "zone_size: " << zone.size 
            << ", min: " << zone.min 
            << ", max: " << zone.max;
        std::cout << ", elements: [";
        for (auto e : zone.elements) {
            std::cout << e << ", ";
        }
        std::cout << "]" << std::endl;
    }
}