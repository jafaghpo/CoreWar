#version 150 core

in vec2 coord_texture;

uniform vec3        color;
uniform vec3        color_font;
uniform sampler2D   first_number;
uniform sampler2D   second_number;

out vec4 out_Color;

void    main()
{
    float   trans;

    trans = (1.0 - texture(first_number, vec2(coord_texture.x, coord_texture.y)).r) * (1.0 - texture(second_number, vec2(coord_texture.x - 0.4, coord_texture.y)).r);
    out_Color = vec4(color.r * trans + color_font.r * (1.0 - trans),
                     color.g * trans + color_font.g * (1.0 - trans),
                     color.b * trans + color_font.b * (1.0 - trans),
                     1.0);
}