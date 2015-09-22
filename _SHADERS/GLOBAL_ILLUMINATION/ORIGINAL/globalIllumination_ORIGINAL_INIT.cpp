    globalIllumination_ORIGINAL_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_globalIllumination_ORIGINAL =                                                                                    

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

    const GLchar *fragmentSource_globalIllumination_ORIGINAL =                                                                                  


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
    
    " 	  varying highp  float  dist;                                                                                       \n"     
    "             highp  float  attenuation;                                                                                \n"     
    
    "//---------------------------------------------------------------------------------------MAIN                        \n" 
    "void main()                                                                                                          \n" 
    "{                                                                                                                    \n" 
    "		     attenuation     = 1.0 / ( dist*dist);                                                                   \n"     //this portion comes from --> Lighthouse3d.com 
    "            //----------------------------------------------------------------------------                           \n"     
        
    "            NormalTex       =  texture2D(NormalMap,  varTexcoord.xy).xyz;                                            \n" 
    "            NormalTex       =  normalize((NormalTex  - 0.5));                                                        \n" 
    "            NdotL1          =  dot(NormalTex, normalize(lightPosition_PASS.xyz));                                           \n"      
   
    "            TextureMap       =  texture2D(Texture1,  varTexcoord.xy);                                            \n"      
    
    "            //NdotL1_INVERT   =  ((NdotL1 * -1.0) + 1.0) * scaleInverse_NdotL1;                                                                                \n"      
    
    "            gl_FragColor    =  TextureMap * clamp(vec4(NdotL1*ambient+.3, NdotL1*ambient+.3, NdotL1*ambient+.3, 1.0)*attenuation, 0.0, 1.0);                                        \n" 
 

 
 
    "}\n";

    
      //--------------------------------------------------------------------------------------------------                    

        globalIllumination_ORIGINAL_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( globalIllumination_ORIGINAL_SHADER_VERTEX, 1, &vertexSource_globalIllumination_ORIGINAL, NULL );                                        
        glCompileShader( globalIllumination_ORIGINAL_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        globalIllumination_ORIGINAL_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( globalIllumination_ORIGINAL_SHADER_FRAGMENT, 1, &fragmentSource_globalIllumination_ORIGINAL, NULL );                                    
        glCompileShader(globalIllumination_ORIGINAL_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( globalIllumination_ORIGINAL_SHADER, globalIllumination_ORIGINAL_SHADER_VERTEX );                                                        
        glAttachShader( globalIllumination_ORIGINAL_SHADER, globalIllumination_ORIGINAL_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(globalIllumination_ORIGINAL_SHADER,   0, "vertex_01");                                                              
        //glBindAttribLocation(globalIllumination_ORIGINAL_SHADER,   1, "normal");                                                            
        glBindAttribLocation(globalIllumination_ORIGINAL_SHADER,   1, "texture");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( globalIllumination_ORIGINAL_SHADER_VERTEX);                                                                             
        glDeleteShader( globalIllumination_ORIGINAL_SHADER_FRAGMENT);                                                                           
        glLinkProgram(globalIllumination_ORIGINAL_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_globalIllumination_ORIGINAL               = glGetUniformLocation(globalIllumination_ORIGINAL_SHADER, "ModelView");                  
        UNIFORM_MODELVIEWPROJ_globalIllumination_ORIGINAL           = glGetUniformLocation(globalIllumination_ORIGINAL_SHADER, "ModelViewProjection");        
        //UNIFORM_MODELVIEWPROJ_INVERSE_globalIllumination_ORIGINAL = glGetUniformLocation(globalIllumination_ORIGINAL_SHADER, "ModelViewProjectionInverse"); 
        UNIFORM_LIGHT_MATRIX_globalIllumination_ORIGINAL            = glGetUniformLocation(globalIllumination_ORIGINAL_SHADER, "LightMatrix");                
        UNIFORM_TEXTURE_MATRIX_globalIllumination_ORIGINAL          = glGetUniformLocation(globalIllumination_ORIGINAL_SHADER, "TextureMatrix");         
        //-----------------------------                                                                                         
        UNIFORM_LIGHT_POSITION_01_globalIllumination_ORIGINAL       = glGetUniformLocation(globalIllumination_ORIGINAL_SHADER, "light_POSITION_01");          
        UNIFORM_offset_globalIllumination_ORIGINAL                  = glGetUniformLocation(globalIllumination_ORIGINAL_SHADER, "offset");                     
        UNIFORM_ambient_globalIllumination_ORIGINAL                 = glGetUniformLocation(globalIllumination_ORIGINAL_SHADER, "ambient"); 
        UNIFORM_scaleInverse_NdotL1_globalIllumination_ORIGINAL     = glGetUniformLocation(globalIllumination_ORIGINAL_SHADER, "scaleInverse_NdotL1");          
        
        //-----------------------------                                                                                         
        UNIFORM_TEXTURE_SHADOW_globalIllumination_ORIGINAL          = glGetUniformLocation(globalIllumination_ORIGINAL_SHADER, "ShadowTexture");              
        UNIFORM_TEXTURE_DOT3_globalIllumination_ORIGINAL            = glGetUniformLocation(globalIllumination_ORIGINAL_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_globalIllumination_ORIGINAL                 = glGetUniformLocation(globalIllumination_ORIGINAL_SHADER, "Texture1");  
