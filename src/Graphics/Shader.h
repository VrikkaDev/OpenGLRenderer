//
// Created by VrikkaDev on 29/03/2023.
//

#ifndef OPENGLRENDERING_SHADER_H
#define OPENGLRENDERING_SHADER_H

#include "pch.h"

class Shader {
public:
    Shader(std::string* vertex, std::string* fragment);
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void Bind() const;
    void UnBind() const;

    int GetLocation(const char* name) const;

    void LoadInt(int location, GLint value);
    void LoadFloat(int location, GLfloat value);

    void LoadVector2(int location, glm::vec2& vec);
    void LoadVector3(int location, glm::vec3& vec);
    void LoadVector4(int location, glm::vec4& vec);
    void LoadMatrix(int location, glm::mat4& matrix);

    void LoadUniform(const std::string& name, glm::mat4& matrix);

    virtual std::map<std::string, int> GetLocations();
private:
    void GetUniforms();
    int m_LocationProjectionMatrix = 0;
    int m_LocationViewMatrix = 0;
    int m_LocationTransformationMatrix = 0;
    int m_LocationMVP = 0;
protected:
    uint32_t m_ShaderProgram;
};


#endif //OPENGLRENDERING_SHADER_H
