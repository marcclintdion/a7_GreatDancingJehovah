    gaussianBlurVerticalPass_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_gaussianBlurVerticalPass =                                                                                    

    " #define highp                                                                                                        \n" 
    "     attribute vec4 vertex_01;                                                                                       \n" 
    "     attribute vec2 texture;                                                                                         \n" 
    " //-------------------------------------------------                                                                 \n"     
    "     uniform        mat4 ModelViewProjection;                                                                        \n" 
    //"     uniform highp   vec4 offset;                                                                                     \n" 

    "     varying highp   vec2 varTexcoord;                                                                                \n" 
 "             highp   vec3 aux;                                                                                        \n" 
    
    " void main()                                                                                                         \n" 
    " {                                                                                                                   \n" 
    "     varTexcoord             = texture;                                                                              \n" 

    "     gl_Position             = ModelViewProjection * vertex_01;                                                      \n" 
    " } \n";   
    //--------------------------------------------------------------------------------------------------------                  

    const GLchar *fragmentSource_gaussianBlurVerticalPass =                                                                                  

    "#ifdef GL_ES                                                                                                           \n" 
    "#else                                                                                                                  \n" 
    "#define highp                                                                                                          \n" 
    "#endif                                                                                                                 \n" 

    "//---------------------------------------------------------------------------------------GLOBALS                       \n" 

    "     uniform sampler2D     Texture1;                                                                                   \n" 
   //"     uniform highp  float  counter;                                                                                    \n"        
    "//--------------------------------------------                                                                         \n" 
    "     varying highp  vec2   varTexcoord;                                                                                \n" 

    "//---------------------------------------------------------------------------------------MAIN                          \n" 
    "void main()                                                                                                            \n" 
    "{                                                                                                                      \n" 


"            //----------------------------------------------------------------------------                             \n" 
    "            tempColor       =  texture2D(Texture1, varTexcoord.);                                                    \n" 
    "            gl_FragColor    =  tempColor;                                              \n" 
    "}\n";

    
      //--------------------------------------------------------------------------------------------------                    

        gaussianBlurVerticalPass_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( gaussianBlurVerticalPass_SHADER_VERTEX, 1, &vertexSource_gaussianBlurVerticalPass, NULL );                                        
        glCompileShader( gaussianBlurVerticalPass_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        gaussianBlurVerticalPass_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( gaussianBlurVerticalPass_SHADER_FRAGMENT, 1, &fragmentSource_gaussianBlurVerticalPass, NULL );                                    
        glCompileShader(gaussianBlurVerticalPass_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( gaussianBlurVerticalPass_SHADER, gaussianBlurVerticalPass_SHADER_VERTEX );                                                        
        glAttachShader( gaussianBlurVerticalPass_SHADER, gaussianBlurVerticalPass_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(gaussianBlurVerticalPass_SHADER,   0, "vertex_01");                                                              
        //glBindAttribLocation(gaussianBlurVerticalPass_SHADER,   1, "normal");                                                            
        glBindAttribLocation(gaussianBlurVerticalPass_SHADER,   1, "texture");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( gaussianBlurVerticalPass_SHADER_VERTEX);                                                                             
        glDeleteShader( gaussianBlurVerticalPass_SHADER_FRAGMENT);                                                                           
        glLinkProgram(gaussianBlurVerticalPass_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_gaussianBlurVerticalPass               = glGetUniformLocation(gaussianBlurVerticalPass_SHADER, "ModelView");                  
        UNIFORM_MODELVIEWPROJ_gaussianBlurVerticalPass           = glGetUniformLocation(gaussianBlurVerticalPass_SHADER, "ModelViewProjection");        
        //UNIFORM_MODELVIEWPROJ_INVERSE_gaussianBlurVerticalPass = glGetUniformLocation(gaussianBlurVerticalPass_SHADER, "ModelViewProjectionInverse"); 
        UNIFORM_LIGHT_MATRIX_gaussianBlurVerticalPass            = glGetUniformLocation(gaussianBlurVerticalPass_SHADER, "LightMatrix");                
        UNIFORM_TEXTURE_MATRIX_gaussianBlurVerticalPass          = glGetUniformLocation(gaussianBlurVerticalPass_SHADER, "TextureMatrix");         
        //-----------------------------                                                                                         
        //UNIFORM_offset_gaussianBlurVerticalPass                  = glGetUniformLocation(gaussianBlurVerticalPass_SHADER, "offset");                     
        UNIFORM_TEXTURE_gaussianBlurVerticalPass                 = glGetUniformLocation(gaussianBlurVerticalPass_SHADER, "Texture1");  
