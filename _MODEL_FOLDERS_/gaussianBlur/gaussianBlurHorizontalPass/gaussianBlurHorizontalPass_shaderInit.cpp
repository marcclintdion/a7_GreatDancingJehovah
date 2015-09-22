    gaussianBlurHorizontalPass_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_gaussianBlurHorizontalPass =                                                                                    

    " #define highp                                                                                                        \n" 
    "     attribute vec4 vertex_01;                                                                                       \n" 
    " //-------------------------------------------------                                                                 \n"     
    "     uniform        mat4 ModelViewProjection;                                                                        \n" 

  
    " void main()                                                                                                         \n" 
    " {                                                                                                                   \n" 

    "     gl_Position             = ModelViewProjection * vertex_01;                                                      \n" 
    " } \n";   
    //--------------------------------------------------------------------------------------------------------                  

    const GLchar *fragmentSource_gaussianBlurHorizontalPass =                                                                                  

    "#ifdef GL_ES                                                                                                           \n" 
    "#else                                                                                                                  \n" 
    "#define highp                                                                                                          \n" 
    "#endif                                                                                                                 \n" 

    "//---------------------------------------------------------------------------------------GLOBALS                       \n" 

    "     uniform sampler2D     Texture1;                                                                                   \n" 
    "//--------------------------------------------                                                                         \n" 
   
    "//---------------------------------------------------------------------------------------MAIN                          \n" 
    "void main()                                                                                                            \n" 
    "{                                                                                                                      \n" 

   "            gl_FragColor    =  vec4(1.0, 1.0, 1.0, 1.0);                                              \n" 
    "}\n";

  
      //--------------------------------------------------------------------------------------------------                    

        gaussianBlurHorizontalPass_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( gaussianBlurHorizontalPass_SHADER_VERTEX, 1, &vertexSource_gaussianBlurHorizontalPass, NULL );                                        
        glCompileShader( gaussianBlurHorizontalPass_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        gaussianBlurHorizontalPass_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( gaussianBlurHorizontalPass_SHADER_FRAGMENT, 1, &fragmentSource_gaussianBlurHorizontalPass, NULL );                                    
        glCompileShader(gaussianBlurHorizontalPass_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( gaussianBlurHorizontalPass_SHADER, gaussianBlurHorizontalPass_SHADER_VERTEX );                                                        
        glAttachShader( gaussianBlurHorizontalPass_SHADER, gaussianBlurHorizontalPass_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(gaussianBlurHorizontalPass_SHADER,   0, "vertex_01");                                                              
        //glBindAttribLocation(gaussianBlurHorizontalPass_SHADER,   1, "normal");                                                            
        glBindAttribLocation(gaussianBlurHorizontalPass_SHADER,   1, "texture");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( gaussianBlurHorizontalPass_SHADER_VERTEX);                                                                             
        glDeleteShader( gaussianBlurHorizontalPass_SHADER_FRAGMENT);                                                                           
        glLinkProgram(gaussianBlurHorizontalPass_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_gaussianBlurHorizontalPass               = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER, "ModelView");                  
        UNIFORM_MODELVIEWPROJ_gaussianBlurHorizontalPass           = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER, "ModelViewProjection");        
        //UNIFORM_MODELVIEWPROJ_INVERSE_gaussianBlurHorizontalPass = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER, "ModelViewProjectionInverse"); 
        UNIFORM_LIGHT_MATRIX_gaussianBlurHorizontalPass            = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER, "LightMatrix");                
        UNIFORM_TEXTURE_MATRIX_gaussianBlurHorizontalPass          = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER, "TextureMatrix");         
        //-----------------------------                                                                                         
        UNIFORM_LIGHT_POSITION_01_gaussianBlurHorizontalPass       = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER, "light_POSITION_01");          
        UNIFORM_offset_gaussianBlurHorizontalPass                  = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER, "offset");                     
        UNIFORM_attenuation_gaussianBlurHorizontalPass                 = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER, "attenuation");  
        UNIFORM_counter_gaussianBlurHorizontalPass                 = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER, "counter");                 
        //-----------------------------                                                                                         
        UNIFORM_TEXTURE_SHADOW_gaussianBlurHorizontalPass          = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER, "ShadowTexture");              
        UNIFORM_TEXTURE_DOT3_gaussianBlurHorizontalPass            = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_gaussianBlurHorizontalPass                 = glGetUniformLocation(gaussianBlurHorizontalPass_SHADER, "Texture1");  
