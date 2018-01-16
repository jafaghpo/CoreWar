#version 150 core

in vec2 coord_texture;

uniform sampler2D   text;

out vec4 out_Color;

void    main()
{
    out_Color = vec4(0.0, 0.0, 0.0, texture(text, coord_texture).r);
}