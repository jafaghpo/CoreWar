#version 150 core

in vec2 in_Vertex;
in vec2 in_Texture;

uniform vec2    offset;
uniform vec2    size;

out vec2    coord_texture;

void    main()
{
    gl_Position = vec4(in_Vertex.x * size.x + offset.x, in_Vertex.y * size.y + offset.y, 0.0, 1.0);
    coord_texture = in_Texture;
}