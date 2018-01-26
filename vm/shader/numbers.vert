#version 150 core

in vec2     in_Vertex;
in vec2     in_Texture;

uniform vec2 pos;

out vec2    coord_texture;

void    main()
{
    gl_Position = vec4(in_Vertex.x, in_Vertex.y, 0.0, 1.0);
    coord_texture = in_Texture;
}