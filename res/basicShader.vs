#version 330 core

layout(location = 0) in vec4 in_position;
layout(location = 1) in vec4 in_color;

out vec4 ex_color;

void main() {
	gl_Position = in_position;
	ex_color = vec4(1,0,0,1);
}