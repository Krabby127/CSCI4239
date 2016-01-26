//  NDC to RGB vertex shader

varying vec4 pos;

void main()
{
    // Set vertex coordinates
    // This is equivalent to ftransform()
    gl_Position = pos = gl_ModelViewProjectionMatrix * gl_Vertex;

    // Map 4D to 3D and map [-1,+1] to [0,1] in all three dimensions
    // gl_FrontColor = 0.5 * (gl_Position/gl_Position.w + 1.0);
}
