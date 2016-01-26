#extension GL_EXT_gpu_shader4: enable

int LFSR_Rand_Gen(in int n)
{
    // <<, ^ and & requires GL_EXT_gpu_shader4.
    n = (n << 13) ^ n;
    return (n * (n*n*15731+789221) + 1376312589) & 0x7fffffff;
}

float LFSR_Rand_Gen_f(in int n)
{
    return float(LFSR_Rand_Gen(n));
}

float noise3f(in vec3 p)
{
    ivec3 ip=ivec3(floor(p));
    vec3 u=fract(p);
    u=u*u*(3.0-2.0*u);

    int n = ip.x + ip.y*57 + ip.z*113;

    float res = mix(mix(mix(LFSR_Rand_Gen_f(n+(0+57*0+113*0)),
                    LFSR_Rand_Gen_f(n+(1+57*0+113*0)),u.x),
                mix(LFSR_Rand_Gen_f(n+(0+57*1+113*0)),
                    LFSR_Rand_Gen_f(n+(1+57*1+113*0)),u.x),u.y),
            mix(mix(LFSR_Rand_Gen_f(n+(0+57*0+113*1)),
                    LFSR_Rand_Gen_f(n+(1+57*1+113*1)),u.x),
                mix(LFSR_Rand_Gen_f(n+(0+57*1+113*1)),
                    LFSR_Rand_Gen_f(n+(1+57*1+113*1)),u.x),u.y),u.z);

    return 1.0 - res*(1.0/1073741824.0);
}



//  Phong lighting

vec4 phong()
{
    //  P is the vertex coordinate on body
    vec3 P = vec3(gl_ModelViewMatrix * gl_Vertex);
    //  N is the object normal at P
    vec3 N = normalize(gl_NormalMatrix * gl_Normal);
    //  Light Position for light 0
    vec3 LightPos = vec3(gl_LightSource[0].position);
    //  L is the light vector
    vec3 L = normalize(LightPos - P);
    //  R is the reflected light vector R = 2(L.N)N - L
    vec3 R = reflect(-L, N);
    //  V is the view vector (eye at the origin)
    vec3 V = normalize(-P);

    //  Diffuse light intensity is cosine of light and normal vectors
    float Id = max(dot(L,N) , 0.0);
    //  Shininess intensity is cosine of light and reflection vectors to a power
    float Is = (Id>0.0) ? pow(max(dot(R,V) , 0.0) , gl_FrontMaterial.shininess) : 0.0;

    float disp = noise3f(gl_Vertex.xyz);
    //  Vertex color
    return (gl_FrontMaterial.emission                          // Emission color
        +    gl_LightModel.ambient*gl_FrontMaterial.ambient    // Global ambient
        +    gl_FrontLightProduct[0].ambient                   // Light[0] ambient
        + Id*gl_FrontLightProduct[0].diffuse                   // Light[0] diffuse
        + Is*gl_FrontLightProduct[0].specular)*disp;           // Light[0] specular
}

void main()
{
    //  Vertex color (using Phong lighting)
    gl_FrontColor = phong();
    //  Texture coordinates
    gl_TexCoord[0] = gl_MultiTexCoord0;
    //  Return fixed transform coordinates for this vertex
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
