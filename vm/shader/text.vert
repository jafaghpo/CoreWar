#version 150 core

in vec2     in_Vertex;
in vec2     in_Texture;

out vec2    coord_texture;

void    main()
{
    gl_Position = vec4(in_Vertex, 0, 1);
    coord_texture = in_Texture;
}