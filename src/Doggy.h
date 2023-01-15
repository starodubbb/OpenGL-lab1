#ifndef GRAPHICS_DOGGY_H
#define GRAPHICS_DOGGY_H

#include "glut.h"
#include "../src/Structs.h"

class Doggy
{
public:
    Doggy()
    {
        //sets all vertices
        Polygon head;
        head.vertices.emplace_back(-0.4F, 0.2F, 0.0F);
        head.vertices.emplace_back(-0.4F, -0.2F, 0.0F);
        head.vertices.emplace_back(-0.7F, -0.2F, 0.0F);
        head.vertices.emplace_back(-0.7F, 0.2F, 0.0F);
        //set quad mode 
        head.glDisplayMode = GL_QUADS;

        Polygon leftEar;
        leftEar.vertices.emplace_back(-0.7F, 0.2F, 0.0F);
        leftEar.vertices.emplace_back(-0.5F, 0.4F, 0.0F);
        leftEar.vertices.emplace_back(-0.7F, 0.6F, 0.0F);
        //set triangle mode 
        leftEar.glDisplayMode = GL_TRIANGLES;

        Polygon rightEar;
        rightEar.vertices.emplace_back(-0.7F, 0.2F, 0.0F);
        rightEar.vertices.emplace_back(-0.4F, 0.5F, 0.0F);
        rightEar.vertices.emplace_back(-0.4F, 0.2F, 0.0F);
        rightEar.glDisplayMode = GL_TRIANGLES;

        Polygon leftFoot;
        leftFoot.vertices.emplace_back(-0.4F, -0.6F, 0.0F);
        leftFoot.vertices.emplace_back(-0.4F, 0.0F, 0.0F);
        leftFoot.vertices.emplace_back(0.0F, 0.0F, 0.0F);
        leftFoot.glDisplayMode = GL_TRIANGLES;

        Polygon rightFoot;
        rightFoot.vertices.emplace_back(0.0F, 0.0F, 0.0F);
        rightFoot.vertices.emplace_back(0.4F, -0.6F, 0.0F);
        rightFoot.vertices.emplace_back(0.4F, 0.0F, 0.0F);
        rightFoot.glDisplayMode = GL_TRIANGLES;

        Polygon stomach;
        stomach.vertices.emplace_back(0.0F, 0.0F, 0.0F);
        stomach.vertices.emplace_back(-0.2F, -0.3F, 0.0F);
        stomach.vertices.emplace_back(0.2F, -0.3F, 0.0F);
        stomach.glDisplayMode = GL_TRIANGLES;

        Polygon tail;
        tail.vertices.emplace_back(0.5F, 0.3F, 0.0F);
        tail.vertices.emplace_back(0.8F, 0.5F, 0.0F);
        tail.vertices.emplace_back(0.7F, 0.2F, 0.0F);
        tail.vertices.emplace_back(0.4F, 0.0F, 0.0F);
        tail.glDisplayMode = GL_QUADS;

        polygons.push_back(head);
        polygons.push_back(leftEar);
        polygons.push_back(rightEar);

        polygons.push_back(stomach);
        polygons.push_back(leftFoot);
        polygons.push_back(rightFoot);

        polygons.push_back(tail);
    }
    ~Doggy() = default;

    //draw all poligons
    void Display() const
    {
        const float outlineColor[3] = { 73.0F / 255, 235.0F / 255, 52.0F / 255 };
        glColor3f(outlineColor[0], outlineColor[1], outlineColor[2]);

        for (const auto& polygon : polygons)
        {
            polygon.Display();
        }
    }

    //draw all contour lines
    void DisplayGrid() const
    {
        const float outlineColor[3] = { 0.0F, 0.0F, 0.0F };
        glColor3f(outlineColor[0], outlineColor[1], outlineColor[2]);

        for (const auto& polygon : polygons)
        {
            polygon.Display(GL_LINE_LOOP);
        }
    }

    //set new vertices positions
    void Move(Vec2 deltaMove)
    {
        for (auto& polygon : polygons)
        {
            for (auto& vertex : polygon.vertices)
            {
                vertex.x += deltaMove.x;
                vertex.y += deltaMove.y;
            }
        }
    }
private:
    std::vector<Polygon> polygons;
};

#endif //GRAPHICS_DOGGY_H
