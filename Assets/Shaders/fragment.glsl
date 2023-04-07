#version 330 core

out vec4 FragColor;

void main()
{
    float r, g, b;
    // notice the 256's instead of 255
    r = (gl_PrimitiveID % 256) / 255.0f;
    g = ((gl_PrimitiveID / 256) % 256) / 255.0f;
    b = ((gl_PrimitiveID / (256 * 256)) % 256) / 255.0f;
    //FragColor = vec4(1.0, 0.5, 0.2, 1.0);
    FragColor = vec4(1.0,1.0,0.5, 1.0);
}