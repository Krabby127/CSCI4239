//  Set the fragment color

varying vec4 pos;

void main()
{
    gl_FragColor = (pos + 1) / (2 * pos[3]);
}
