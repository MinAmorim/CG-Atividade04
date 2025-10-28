#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"


class material {
  public:
    color k_ambient;
    color k_diffuse;
    
    color k_specular;
    int shininess;

    material(const color& ka, const color& kd, const color& ks, int m)
      : k_ambient(ka), k_diffuse(kd), k_specular(ks), shininess(m) {}
};

#endif