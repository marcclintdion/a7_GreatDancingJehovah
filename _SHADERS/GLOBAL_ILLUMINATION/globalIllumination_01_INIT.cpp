    globalIllumination_01_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_globalIllumination_01 =                                                                                    

    "     attribute vec4 vertex_01;                                                                                       \n" 
    " //-------------------------------------------------                                                                 \n"     
    "     uniform        mat4 ModelViewProjection;                                                                        \n" 
  
    " void main()                                                                                                         \n" 
    " {                                                                                                                   \n" 
    
  
    "     gl_Position             = ModelViewProjection * vertex_01;                                                      \n" 
    
    " } \n";   
    //--------------------------------------------------------------------------------------------------------                  

    const GLchar *fragmentSource_globalIllumination_01 =                                                                                  


    "     uniform highp  float  ambient;                                                                                  \n" 

   
    "//---------------------------------------------------------------------------------------MAIN                        \n" 
    "void main()                                                                                                          \n" 
    "{                                                                                                                    \n" 
       
 
    "            gl_FragColor    =  vec4(ambient, ambient, ambient,  1.0);                                        \n" 
 

 
 
    "}\n";

    
      //--------------------------------------------------------------------------------------------------                    

        globalIllumination_01_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( globalIllumination_01_SHADER_VERTEX, 1, &vertexSource_globalIllumination_01, NULL );                                        
        glCompileShader( globalIllumination_01_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        globalIllumination_01_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( globalIllumination_01_SHADER_FRAGMENT, 1, &fragmentSource_globalIllumination_01, NULL );                                    
        glCompileShader(globalIllumination_01_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( globalIllumination_01_SHADER, globalIllumination_01_SHADER_VERTEX );                                                        
        glAttachShader( globalIllumination_01_SHADER, globalIllumination_01_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(globalIllumination_01_SHADER,   0, "vertex_01");                                                              
        //glBindAttribLocation(globalIllumination_01_SHADER,   1, "normal");                                                            
        glBindAttribLocation(globalIllumination_01_SHADER,   1, "texture");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( globalIllumination_01_SHADER_VERTEX);                                                                             
        glDeleteShader( globalIllumination_01_SHADER_FRAGMENT);                                                                           
        glLinkProgram(globalIllumination_01_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_globalIllumination_01               = glGetUniformLocation(globalIllumination_01_SHADER, "ModelView");                  
        UNIFORM_MODELVIEWPROJ_globalIllumination_01           = glGetUniformLocation(globalIllumination_01_SHADER, "ModelViewProjection");        
        //UNIFORM_MODELVIEWPROJ_INVERSE_globalIllumination_01 = glGetUniformLocation(globalIllumination_01_SHADER, "ModelViewProjectionInverse"); 
        UNIFORM_LIGHT_MATRIX_globalIllumination_01            = glGetUniformLocation(globalIllumination_01_SHADER, "LightMatrix");                
        UNIFORM_TEXTURE_MATRIX_globalIllumination_01          = glGetUniformLocation(globalIllumination_01_SHADER, "TextureMatrix");         
        //-----------------------------                                                                                         
        UNIFORM_LIGHT_POSITION_01_globalIllumination_01       = glGetUniformLocation(globalIllumination_01_SHADER, "light_POSITION_01");          
        UNIFORM_offset_globalIllumination_01                  = glGetUniformLocation(globalIllumination_01_SHADER, "offset");                     
        UNIFORM_ambient_globalIllumination_01                 = glGetUniformLocation(globalIllumination_01_SHADER, "ambient"); 
        UNIFORM_scaleInverse_NdotL1_globalIllumination_01    = glGetUniformLocation(globalIllumination_01_SHADER, "scaleInverse_NdotL1");       
        //-----------------------------                                                                                         
        UNIFORM_TEXTURE_SHADOW_globalIllumination_01          = glGetUniformLocation(globalIllumination_01_SHADER, "ShadowTexture");              
        UNIFORM_TEXTURE_DOT3_globalIllumination_01            = glGetUniformLocation(globalIllumination_01_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_globalIllumination_01                 = glGetUniformLocation(globalIllumination_01_SHADER, "Texture1");  
