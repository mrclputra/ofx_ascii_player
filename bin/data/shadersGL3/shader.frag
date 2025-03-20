// fragment shader

#version 150

uniform sampler2DRect tex0;  // video texture
uniform vec2 texSize; // original texture size
uniform vec2 windowSize; // window size

out vec4 outputColor;

void main()
{
	// calculate normalized position in the window (0 to 1)
	vec2 normalizedPos = gl_FragCoord.xy / windowSize;

	// convert to texture coordinates
	// this maps window coordinates to texture coordinates
	vec2 texCoord = vec2(
		normalizedPos.x * texSize.x,
		(1.0 - normalizedPos.y) * texSize.y // flip y
	);

	// sample video texture at said position
	vec4 videoColor = texture(tex0, texCoord);

	// TODO: do modifications or analysis here
	float r = videoColor.r;
    float g = videoColor.g;
    float b = videoColor.b / 2.0;
    float a = 1.0;

	outputColor = vec4(r, g, b, a);
}