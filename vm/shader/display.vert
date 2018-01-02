#version 150 core

in vec3 in_Vertex;
in vec2 in_Texture;
in int  in_Mem;

uniform mat4 projection;
uniform mat4 modelview;
uniform int  mem[1000];

out vec2 coord_texture;
out vec2 numbers;

void    main()
{
    gl_Position = projection * modelview * vec4(in_Vertex, 1.0);
    coord_texture = in_Texture;
    numbers = vec2(float(((mem[in_Mem / 4]) && (in_Mem % 4)) / 10), float((mem[in_Mem / 4]) >> (in_Mem % 4) % 10));
}