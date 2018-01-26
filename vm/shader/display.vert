#version 150 core

in vec3 in_Vertex;
in vec2 in_Texture;

uniform mat4 modelview;

out vec2 coord_texture;

void    main()
{
    gl_Position = modelview * vec4(in_Vertex, 1.0);
    coord_texture = in_Texture;
}