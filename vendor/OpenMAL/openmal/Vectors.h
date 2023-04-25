//
// Created by VrikkaDev on 05/04/2023.
//

#ifndef OPENMAL_VECTORS_H
#define OPENMAL_VECTORS_H

namespace OpenMAL{
    struct Vec2{
        union{
            struct {
                float x, y;
            };
            struct {
                float array[2];
            };
        };

        bool operator==(const Vec2& other) const {
            return x == other.x && y == other.y;
        }
    };

    struct Vec3{
        union{
            struct {
                float x, y, z;
            };
            struct {
                float array[3];
            };
        };

        bool operator==(const Vec3& other) const {
            return x == other.x && y == other.y && z == other.z;
        }
    };

    static inline Vec3 read_vec3(const char* buffer) {
        Vec3 v{};
        memcpy(&v.x, buffer, sizeof(float));
        memcpy(&v.y, buffer + sizeof(float), sizeof(float));
        memcpy(&v.z, buffer + 2 * sizeof(float), sizeof(float));
        return v;
    }
}

#endif //OPENMAL_VECTORS_H
