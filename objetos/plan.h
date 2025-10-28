#ifndef PLANE_H
#define PLANE_H

#include "hittable.h"
#include "vec3.h"
#include <memory>

class plane : public hittable {
  public:
    plane(const point3& p, const vec3& n, std::shared_ptr<material> m)
      : point_on_plane(p), normal(unit_vector(n)), mat(m) {}

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        
        double denominator = dot(normal, r.direction());
        if (std::abs(denominator) < 1e-8) {
            return false;
        }

      
        double t = dot(point_on_plane - r.origin(), normal) / denominator;

        if (t <= ray_tmin || t > ray_tmax) {
            return false;
        }

        rec.t = t;
        rec.p = r.at(t);
        
        rec.mat = mat;

        if (dot(r.direction(), normal) > 0.0) {
            rec.normal = -normal;
        } else {
            rec.normal = normal;
        }

        return true;
    }

  private:
    point3 point_on_plane;
    vec3 normal;
    std::shared_ptr<material> mat;
};

#endif