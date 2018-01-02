#version 150 core

in vec2 coord_texture;
in vec2 numbers;

uniform vec3        color;
uniform sampler2D   back_ground;
uniform sampler2D   first_number[16];

out vec4 out_Color;

void    main()
{
    float   trans;
    int     x, y;

    x = int(numbers.x);
    y = int(numbers.y);
    trans = (1.0 - texture(first_number[x], vec2(coord_texture.x, coord_texture.y)).r) * (1.0 - texture(first_number[y], vec2(coord_texture.x - 0.4, coord_texture.y)).r);
    out_Color.r = 1.f * trans;
    out_Color.g = 1.f * trans;
    out_Color.b = 1.f * trans;
    out_Color.a = 1.0;
}
