#include "zonemaps.h"
#include <iostream>

template<typename T>
zonemap<T>::zonemap(std::vector<T> _elements, uint _num_elements_per_zone)
{
    // constructor
    elements = _elements;
    num_elements_per_zone = _num_elements_per_zone;
    num_zones = elements.size() / num_elements_per_zone + 1;

    this->build();
    this->print();
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
    return false;
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