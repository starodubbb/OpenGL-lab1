#ifndef GRAPHICS_STRUCTS_H
#define GRAPHICS_STRUCTS_H

#include <iostream>
#include <vector>

#include "glut.h"

struct Vec2
{
    float x = 0.0F;
    float y = 0.0F;
};

struct Vec3
{
    float x = 0.0F;
    float y = 0.0F;
    float z = 0.0F;
};

struct Vertex : public Vec3
{
    explicit Vertex() = default;
    explicit Vertex(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    ~Vertex() = default;
};

struct Polygon
{
    explicit Polygon() = default;
    explicit Polygon(unsigned int glDisplayMode) : glDisplayMode(glDisplayMode) {};

    ~Polygon() = default;

    //draw all poligons
    virtual void Display(unsigned int displayMode = 0) const
    {
        if (displayMode)
        {
            //start drawing
            glBegin(displayMode);
        }
        else
        {
            //start drawing 
            glBegin(glDisplayMode);
        }
        for (const auto& v : vertices)
        {
            //specifies a vertex for drawing
            glVertex3f(v.x, v.y, v.z);
        }
        //end drawing
        glEnd();
    }

    std::vector<Vertex> vertices;
    unsigned int glDisplayMode = GL_POLYGON;
};

#endif //GRAPHICS_STRUCTS_H
