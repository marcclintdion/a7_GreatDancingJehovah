    baseLighting_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_baseLighting =                                                                                    

    " #define highp                                                                                                        \n" 
    "     attribute vec4 vertex_01;                                                                                       \n" 
    "     attribute vec2 texture;                                                                                         \n" 
    " //-------------------------------------------------                                                                 \n"     
    "     uniform   highp vec4 light_POSITION_01;                                                                          \n" 
    "     uniform        mat4 ModelView;                                                                                  \n" 
    "     uniform        mat4 ModelViewProjection;                                                                        \n" 
    "     uniform        mat4 LightMatrix;                                                                                \n" 
    "     uniform        mat4 TextureMatrix;                                                                              \n" 
    "     uniform highp   vec4 offset;                                                                                     \n" 
    " //-------------------------------------------------                                                                 \n" 
    "     varying highp   vec4 TEMP_shadowTexcoord;                                                                        \n" 
    "     varying highp   vec4 shadowTexcoord;                                                                             \n" 
    "     varying highp   vec4 lightPosition_PASS;                                                                         \n" 
    "     varying highp   vec2 varTexcoord;                                                                                \n" 
    " //-------------------------------------------------                                                                 \n" 
    " 	  varying highp  float dist;                                                                                       \n" 
    "             highp   vec4 ecPos;                                                                                      \n" 
    "             highp   vec3 aux;                                                                                        \n" 
    
    " void main()                                                                                                         \n" 
    " {                                                                                                                   \n" 
    "     varTexcoord             = texture;                                                                              \n" 
    "     TEMP_shadowTexcoord     = TextureMatrix * ModelView * vertex_01;                                                \n" 
    "     TEMP_shadowTexcoord    += offset;                                                                               \n" 
    "     shadowTexcoord          = TEMP_shadowTexcoord  * 0.025;                                                         \n" 
    "     lightPosition_PASS      = normalize(LightMatrix * light_POSITION_01 - vertex_01);                               \n" 
    "     gl_Position             = ModelViewProjection * vertex_01;                                                      \n" 
    " } \n";   
    //--------------------------------------------------------------------------------------------------------                  

    const GLchar *fragmentSource_baseLighting =                                                                                  

    "#ifdef GL_ES                                                                                                           \n" 
    "#else                                                                                                                  \n" 
    "#define highp                                                                                                          \n" 
    "#endif                                                                                                                 \n" 

    "//---------------------------------------------------------------------------------------GLOBALS                       \n" 

    "     uniform sampler2D     Texture1;                                                                                   \n" 
    "     uniform sampler2D     NormalMap;                                                                                  \n" 
    "     uniform sampler2D     ShadowTexture;                                                                              \n" 
    "     uniform highp  float  attenuation;                                                                                \n" 
    "     uniform highp  float  counter;                                                                                    \n"        
    "//--------------------------------------------                                                                         \n" 
    "     varying highp  vec4   lightPosition_PASS;                                                                         \n" 
    "     varying highp  vec2   varTexcoord;                                                                                \n" 
    "     varying highp  vec4   shadowTexcoord;                                                                             \n" 
    "//--------------------------------------------                                                                         \n" 
    "             highp  vec4   tempColor;                                                                                  \n" 
    "             highp  vec4   shadow;                                                                                     \n"     
    "             highp  vec3   NormalTex;                                                                                  \n" 
    "             highp  float  shadowMixLayers;                                                                            \n"      
    "             highp  float  shadowLayer_01;                                                                             \n"     
    "             highp  float  shadowLayer_02;                                                                             \n"  
    "             highp  float  shadowLayer_03;                                                                             \n"     
    "             highp  float  shadowLayer_04;                                                                             \n"   
    "             //------------------------                                                                                \n" 
    "             highp  float  NdotL1;                                                                                     \n" 
    "//---------------------------------------------------------------------------------------MAIN                          \n" 
    "void main()                                                                                                            \n" 
    "{                                                                                                                      \n" 
    "            //----------------------------------------------------------------------------                             \n"     
    "            NormalTex       =  texture2D(NormalMap,  varTexcoord.xy).xyz;                                              \n" 
    "            NormalTex       =  normalize((NormalTex  - 0.5));                                                          \n" 
    "            NdotL1          =  dot(NormalTex, lightPosition_PASS.xyz);                                                 \n"   
    "            //----------------------------------------------------------------------------                             \n"        
    "            shadowLayer_01  =  texture2D(ShadowTexture, shadowTexcoord.st).r;                                          \n" 
    "            shadowLayer_02  =  texture2D(ShadowTexture, shadowTexcoord.st).g;                                          \n"     
    "            shadowMixLayers =  shadowLayer_01 * shadowLayer_02;                                                        \n" 
    "            shadow          =  vec4(shadowMixLayers,                                                                   \n" 
    "                                    shadowMixLayers,                                                                   \n" 
    "                                    shadowMixLayers,                                                                   \n" 
    "                                    shadowMixLayers);                                                                  \n" 
    "            //----------------------------------------------------------------------------                             \n" 
    "            tempColor       =  texture2D(Texture1, varTexcoord.xy);                                                    \n" 
    "            gl_FragColor    =  tempColor * shadow * NdotL1 * attenuation;                                              \n" 
    "}\n";

    
      //--------------------------------------------------------------------------------------------------                    

        baseLighting_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( baseLighting_SHADER_VERTEX, 1, &vertexSource_baseLighting, NULL );                                        
        glCompileShader( baseLighting_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        baseLighting_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( baseLighting_SHADER_FRAGMENT, 1, &fragmentSource_baseLighting, NULL );                                    
        glCompileShader(baseLighting_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( baseLighting_SHADER, baseLighting_SHADER_VERTEX );                                                        
        glAttachShader( baseLighting_SHADER, baseLighting_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(baseLighting_SHADER,   0, "vertex_01");                                                              
        //glBindAttribLocation(baseLighting_SHADER,   1, "normal");                                                            
        glBindAttribLocation(baseLighting_SHADER,   1, "texture");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( baseLighting_SHADER_VERTEX);                                                                             
        glDeleteShader( baseLighting_SHADER_FRAGMENT);                                                                           
        glLinkProgram(baseLighting_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_baseLighting               = glGetUniformLocation(baseLighting_SHADER, "ModelView");                  
        UNIFORM_MODELVIEWPROJ_baseLighting           = glGetUniformLocation(baseLighting_SHADER, "ModelViewProjection");        
        //UNIFORM_MODELVIEWPROJ_INVERSE_baseLighting = glGetUniformLocation(baseLighting_SHADER, "ModelViewProjectionInverse"); 
        UNIFORM_LIGHT_MATRIX_baseLighting            = glGetUniformLocation(baseLighting_SHADER, "LightMatrix");                
        UNIFORM_TEXTURE_MATRIX_baseLighting          = glGetUniformLocation(baseLighting_SHADER, "TextureMatrix");         
        //-----------------------------                                                                                         
        UNIFORM_LIGHT_POSITION_01_baseLighting       = glGetUniformLocation(baseLighting_SHADER, "light_POSITION_01");          
        UNIFORM_offset_baseLighting                  = glGetUniformLocation(baseLighting_SHADER, "offset");                     
        UNIFORM_attenuation_baseLighting                 = glGetUniformLocation(baseLighting_SHADER, "attenuation");  
        UNIFORM_counter_baseLighting                 = glGetUniformLocation(baseLighting_SHADER, "counter");                 
        //-----------------------------                                                                                         
        UNIFORM_TEXTURE_SHADOW_baseLighting          = glGetUniformLocation(baseLighting_SHADER, "ShadowTexture");              
        UNIFORM_TEXTURE_DOT3_baseLighting            = glGetUniformLocation(baseLighting_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_baseLighting                 = glGetUniformLocation(baseLighting_SHADER, "Texture1");  
