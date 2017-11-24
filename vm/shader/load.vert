#version 150 core

in vec2 in_Vertex;

uniform float   size;
uniform float   offset;

void    main()
{
    gl_Position = vec4(in_Vertex.x * size + offset, in_Vertex.y, 0.0, 1.0);
}