    globalIllumination_SQUARED_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_globalIllumination_SQUARED =                                                                                    

    "     attribute vec4 vertex_01;                                                                                       \n" 
    "     attribute vec2 texture;                                                                                         \n" 
    " //-------------------------------------------------                                                                 \n"     
    "     uniform   highp vec4 light_POSITION_01;                                                                          \n" 
    "     uniform        mat4 ModelView;                                                                                  \n" 
    "     uniform        mat4 ModelViewProjection;                                                                        \n" 
    "   //uniform        mat4 ModelViewProjectionInverse;                                                                 \n" 
    "     uniform        mat4 LightMatrix;                                                                                \n" 
    "     uniform        mat4 TextureMatrix;                                                                              \n" 
    "     uniform highp   vec4 offset;                                                                                     \n" 
   "    //uniform highp  float counter;                                                                                    \n" 
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
    
    
    "		     ecPos = ModelView * vertex_01;                                                                           \n" //this portion comes from --> Lighthouse3d.com
    "		     aux   = vec3(light_POSITION_01 - ecPos);                                                                 \n" //this portion comes from --> Lighthouse3d.com 
    "		     dist = length(aux);                                                                                      \n" //this portion comes from --> Lighthouse3d.com 
      
    
    "     varTexcoord             = texture;                                                                              \n" 

    "     lightPosition_PASS      = LightMatrix * light_POSITION_01 - vertex_01;                                 \n" 
    
    "     gl_Position             = ModelViewProjection * vertex_01;                                                      \n" 
    
    " } \n";   
    //--------------------------------------------------------------------------------------------------------                  

    const GLchar *fragmentSource_globalIllumination_SQUARED =                                                                                  


    "//---------------------------------------------------------------------------------------GLOBALS                     \n" 
    "     uniform sampler2D     NormalMap;                                                                                  \n" 
    "     uniform sampler2D     Texture1;                                                                                  \n"     
   "//--------------------------------------------                                                                       \n" 
    "     varying highp  vec4   lightPosition_PASS;                                                                       \n" 
    "     varying highp  vec2   varTexcoord;                                                                              \n" 
   "//--------------------------------------------                                                                        \n" 
    "             highp  vec3   NormalTex;                                                                                \n" 
    "     uniform highp  float  ambient;                                                                                  \n" 
    "     uniform highp  float  scaleInverse_NdotL1;                                                                                  \n" 
    "             highp  vec4   TextureMap;                                                                                \n"   
 
    "             highp  float  NdotL1;                                                                                    \n" 
    "             highp  float  NdotL1_INVERT;                                                                             \n"     
    "             highp  float  temp_INTENSITY;                                                                             \n"   
    
    " 	  varying highp  float  dist;                                                                                       \n"     
    "             highp  float  attenuation;                                                                                \n"     
    
    "//---------------------------------------------------------------------------------------MAIN                        \n" 
    "void main()                                                                                                          \n" 
    "{                                                                                                                    \n" 
    "		     attenuation     = 1.0 / (dist);                                                                   \n"     //this portion comes from --> Lighthouse3d.com 
    "            //----------------------------------------------------------------------------                           \n"     
        
    "            NormalTex       =  texture2D(NormalMap,  varTexcoord.xy).xyz;                                            \n" 
    "            NormalTex       =  normalize((NormalTex  - 0.5));                                                        \n" 
    "            NdotL1          =  dot(NormalTex, normalize(lightPosition_PASS.xyz));                                    \n"      
    
   
    "            NdotL1_INVERT   =  ((NdotL1 * -1.0) + (1.0 )) * scaleInverse_NdotL1;                                     \n"      
    
    "            temp_INTENSITY   =  (NdotL1  - 0.5) + NdotL1_INVERT ;                                                    \n"      
    
    "            temp_INTENSITY   -=  min(temp_INTENSITY, 0.3);                                                           \n"  
    "            temp_INTENSITY   *=  temp_INTENSITY;                                                           \n"    
  
   
    "            TextureMap       =  texture2D(Texture1,  varTexcoord.xy);                                            \n"         
   
    "            gl_FragColor    =  TextureMap * clamp(vec4(temp_INTENSITY, temp_INTENSITY, temp_INTENSITY, 1.0)*attenuation, 0.0, 1.0)* ambient;                                        \n" 
 

 
 
    "}\n";
/*
    "            NdotL1_INVERT   =  ((NdotL1 * -1.0) + (1.0 )) * scaleInverse_NdotL1;                                                 \n"      
    
    "            temp_INTENSITY   =  (NdotL1  - 0.5) + NdotL1_INVERT ;                                                 \n"      
    
    "            temp_INTENSITY   -=  min(temp_INTENSITY, 0.3);              \n"  
    
    
    "            gl_FragColor    =  clamp(vec4(temp_INTENSITY, temp_INTENSITY, temp_INTENSITY, 1.0)*attenuation, 0.0, 1.0)* ambient;                                        \n" 
*/ 
    
      //--------------------------------------------------------------------------------------------------                    

        globalIllumination_SQUARED_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( globalIllumination_SQUARED_SHADER_VERTEX, 1, &vertexSource_globalIllumination_SQUARED, NULL );                                        
        glCompileShader( globalIllumination_SQUARED_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        globalIllumination_SQUARED_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( globalIllumination_SQUARED_SHADER_FRAGMENT, 1, &fragmentSource_globalIllumination_SQUARED, NULL );                                    
        glCompileShader(globalIllumination_SQUARED_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( globalIllumination_SQUARED_SHADER, globalIllumination_SQUARED_SHADER_VERTEX );                                                        
        glAttachShader( globalIllumination_SQUARED_SHADER, globalIllumination_SQUARED_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(globalIllumination_SQUARED_SHADER,   0, "vertex_01");                                                              
        //glBindAttribLocation(globalIllumination_SQUARED_SHADER,   1, "normal");                                                            
        glBindAttribLocation(globalIllumination_SQUARED_SHADER,   1, "texture");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( globalIllumination_SQUARED_SHADER_VERTEX);                                                                             
        glDeleteShader( globalIllumination_SQUARED_SHADER_FRAGMENT);                                                                           
        glLinkProgram(globalIllumination_SQUARED_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_globalIllumination_SQUARED               = glGetUniformLocation(globalIllumination_SQUARED_SHADER, "ModelView");                  
        UNIFORM_MODELVIEWPROJ_globalIllumination_SQUARED           = glGetUniformLocation(globalIllumination_SQUARED_SHADER, "ModelViewProjection");        
        //UNIFORM_MODELVIEWPROJ_INVERSE_globalIllumination_SQUARED = glGetUniformLocation(globalIllumination_SQUARED_SHADER, "ModelViewProjectionInverse"); 
        UNIFORM_LIGHT_MATRIX_globalIllumination_SQUARED            = glGetUniformLocation(globalIllumination_SQUARED_SHADER, "LightMatrix");                
        UNIFORM_TEXTURE_MATRIX_globalIllumination_SQUARED          = glGetUniformLocation(globalIllumination_SQUARED_SHADER, "TextureMatrix");         
        //-----------------------------                                                                                         
        UNIFORM_LIGHT_POSITION_01_globalIllumination_SQUARED       = glGetUniformLocation(globalIllumination_SQUARED_SHADER, "light_POSITION_01");          
        UNIFORM_offset_globalIllumination_SQUARED                  = glGetUniformLocation(globalIllumination_SQUARED_SHADER, "offset");                     
        UNIFORM_ambient_globalIllumination_SQUARED                 = glGetUniformLocation(globalIllumination_SQUARED_SHADER, "ambient"); 
        UNIFORM_scaleInverse_NdotL1_globalIllumination_SQUARED     = glGetUniformLocation(globalIllumination_SQUARED_SHADER, "scaleInverse_NdotL1");          
        
        //-----------------------------                                                                                         
        UNIFORM_TEXTURE_SHADOW_globalIllumination_SQUARED          = glGetUniformLocation(globalIllumination_SQUARED_SHADER, "ShadowTexture");              
        UNIFORM_TEXTURE_DOT3_globalIllumination_SQUARED            = glGetUniformLocation(globalIllumination_SQUARED_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_globalIllumination_SQUARED                 = glGetUniformLocation(globalIllumination_SQUARED_SHADER, "Texture1");  
