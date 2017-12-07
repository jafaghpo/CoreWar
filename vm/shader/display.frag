#version 150 core

in vec2 coord_texture;

uniform vec3        color;
uniform sampler2D   back_ground;
uniform sampler2D   first_number[16];
uniform sampler2D   second_number[16];

out vec4 out_Color;

void    main()
{
    float   trans;

    trans = (1.0 - texture(first_number[5], coord_texture).r) * (1.0 - texture(second_number[6], coord_texture).r);
    out_Color.r = 1.f * trans;
    out_Color.g = 1.f * trans;
    out_Color.b = 1.f * trans;
    out_Color.a = 1.0;
}
