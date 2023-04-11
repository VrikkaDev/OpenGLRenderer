//
// Created by VrikkaDev on 09/04/2023.
//

#ifndef OPENGLRENDERING_TEXTURE_H
#define OPENGLRENDERING_TEXTURE_H

#include "pch.h"

class Texture {
public:
    Texture(const std::string& filepath);
    ~Texture();

    void Bind(uint32_t slot = 0) const;
    void Unbind() const;

    inline int GetWidth() const { return m_Width; }
    inline int GetHeight() const { return m_Height; }
private:
    uint32_t m_TextureId;
    std::string m_FilePath;
    unsigned char* m_LocalBuffer;
    int m_Width, m_Height, m_BPP;
};


#endif //OPENGLRENDERING_TEXTURE_H
