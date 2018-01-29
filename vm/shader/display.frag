#version 150 core

in vec2 coord_texture;

uniform vec3        color;
uniform vec3        color_font;
uniform vec3        color_text;
uniform sampler2D   text;
uniform sampler2D   first_number;
uniform sampler2D   second_number;

out vec4 out_Color;

void    main()
{
    float   trans_font;
    float   trans_text;

    trans_font = (1.0 - texture(first_number, vec2(coord_texture.x, coord_texture.y)).r) * (1.0 - texture(second_number, vec2(coord_texture.x - 0.4, coord_texture.y)).r);
    trans_text = texture(text, coord_texture).r;

    out_Color = vec4(color.r * trans_text + color_text.r * (1.0 - trans_text),
                     color.g * trans_text + color_text.g * (1.0 - trans_text),
                     color.b * trans_text + color_text.b * (1.0 - trans_text),
                     1.0);

    out_Color = vec4(out_Color.r * trans_font + color_font.r * (1.0 - trans_font),
                     out_Color.g * trans_font + color_font.g * (1.0 - trans_font),
                     out_Color.b * trans_font + color_font.b * (1.0 - trans_font),
                     1.0);
}