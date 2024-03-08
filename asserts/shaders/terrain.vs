#version 330
layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 InColor;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform float gMinHeight;
uniform float gMaxHeight;

out vec4 Color;

void main() {
    gl_Position = projection * view * model * vec4(Position, 1.0);
    
    float DeltaHeight = gMaxHeight - gMinHeight;
    float HeightRatio = (Position.y - gMinHeight) / DeltaHeight;
    float c = HeightRatio * 0.8 + 0.2;
    Color = vec4(c, c, c, 1.0);
}
