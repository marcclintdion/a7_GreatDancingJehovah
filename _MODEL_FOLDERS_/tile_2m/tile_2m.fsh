#ifdef GL_ES
#else
#define lowp
#endif
 
    uniform sampler2D  Texture1;
    uniform sampler2D  NormalMap;
    uniform sampler2D  ShadowTexture;
                                                                                           //uniform lowp  float counter;
    //--------------------------------------------
    varying lowp vec4  lightPosition_PASS;
    varying lowp vec2  varTexcoord;
    varying lowp vec4  shadowTexcoord;
    //--------------------------------------------
            lowp vec4  tempColor;
            lowp vec3  NormalTex;
            lowp vec4  shadow;
            //------------------------
            lowp float NdotL1;
//---------------------------------------------------------------------------------------MAIN

void main()
{
            shadow = texture2D(ShadowTexture, shadowTexcoord.st, 0.0);
            //----------------------------------------------------------------------------        
            NormalTex       =  texture2D(NormalMap,  varTexcoord.xy).xyz;
            NormalTex       =  normalize((NormalTex  - 0.5));
            NdotL1          =  dot(NormalTex, lightPosition_PASS.xyz);
  
            tempColor       =  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1;  
    
            gl_FragColor    =  tempColor * shadow;

}

























//==============================================================================================================
/*
    gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0) * 0.3                 
    
    +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1      //ambient * diffuse^2
    
    +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, 100.0) ; //ambient * specular
*/
