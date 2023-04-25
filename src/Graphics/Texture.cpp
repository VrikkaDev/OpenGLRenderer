//
// Created by VrikkaDev on 09/04/2023.
//

#include "Texture.h"

Texture::Texture(const std::string& filepath) :
        m_TextureId(0), m_FilePath(filepath), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0){

    stbi_set_flip_vertically_on_load(1);
    m_LocalBuffer = stbi_load(filepath.c_str(), &m_Width, &m_Height, &m_BPP, 4);

    glGenTextures(1, &m_TextureId);
    glBindTexture(GL_TEXTURE_2D, m_TextureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   /* glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);*/

    if (m_LocalBuffer) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(m_LocalBuffer);
    }
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture() {
    glDeleteTextures(1, &m_TextureId);
}

void Texture::Bind(uint32_t slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_TextureId);
}

void Texture::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}
