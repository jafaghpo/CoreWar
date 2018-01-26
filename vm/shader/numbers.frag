#version 150 core

in vec2 coord_texture;

uniform sampler2D   text;
uniform vec3        color_font;

out vec4 out_Color;

void    main()
{
    out_Color = vec4(color_font.r, color_font.g, color_font.b, texture(text, coord_texture).r);
}