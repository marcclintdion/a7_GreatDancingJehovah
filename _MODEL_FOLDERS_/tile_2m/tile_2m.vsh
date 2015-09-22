#define lowp
    
    
    attribute vec4 vertex_01;
    attribute vec2 texture;
    
    uniform   lowp vec4 light_POSITION_01;

    uniform        mat4 ModelView;        
    uniform        mat4 ModelViewProjection;
    uniform        mat4 ModelViewProjectionInverse;    
    uniform        mat4 LightMatrix;

    uniform lowp   vec4 offset;
    uniform lowp   vec4 tileJump;
  //uniform lowp  float counter;
//-------------------------------------------------    
    varying lowp   vec4 TEMP_shadowTexcoord;
    varying lowp   vec4 shadowTexcoord;    
    varying lowp   vec4 lightPosition_PASS;
    varying lowp   vec2 varTexcoord;
//-------------------------------------------------    

void main()
{
    varTexcoord             = texture;
    
    TEMP_shadowTexcoord     = vec4(texture, 1.0, 1.0);
    TEMP_shadowTexcoord    += offset + tileJump;
    
    shadowTexcoord          = TEMP_shadowTexcoord * 0.2;

    lightPosition_PASS      = normalize(LightMatrix * light_POSITION_01);    

    gl_Position             = ModelViewProjection * vertex_01;
}











