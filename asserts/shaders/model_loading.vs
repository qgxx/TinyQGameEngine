#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBiTangent;

out vec2 TexCoords;
out vec3 Tangent;
out vec3 BiTangent;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out VS_OUT {
    vec3 normal;
} vs_out;

void main() {
    mat3 normalMatrix = mat3(transpose(inverse(view * model)));
    vs_out.normal = vec3(vec4(normalMatrix * aNormal, 0.0));
    
    TexCoords = aTexCoords;
    Tangent = aTangent;
    BiTangent = aBiTangent;    
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}