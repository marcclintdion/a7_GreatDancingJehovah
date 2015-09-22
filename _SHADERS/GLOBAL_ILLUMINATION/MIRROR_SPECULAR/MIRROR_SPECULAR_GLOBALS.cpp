                                  //GLfloat     goldenSunset_LIGHT_POSITION_01[]      =  {0, 2.39002, 0, 1.0};//----------------QUADRATRIC_ATTENUATION
                                  //GLfloat     ambient_goldenSunset                  =   0.175;
                               
                                  
                                  //--------------------------------------------------
                                  GLfloat     offset_MIRROR_SPECULAR[]                 = { 0.0,  0.0,  0.0,  1.0};                                           
                                  GLfloat     tileJump_MIRROR_SPECULAR[]               = { 0.0,  0.0,  0.0,  1.0};                                           
                                  //=====================================================================================|_SHADER
                                  GLuint      MIRROR_SPECULAR_SHADER_VERTEX;                                                                                 
                                  GLuint      MIRROR_SPECULAR_SHADER_FRAGMENT;                                                                               
                                  GLuint      MIRROR_SPECULAR_SHADER;     
                                  //-------------------------------------------------------------------------------------|_CONFIGURABLE_UNIFORMS
                                  GLuint      UNIFORM_LIGHT_POSITION_01_MIRROR_SPECULAR;                                                                     
                                  GLuint      UNIFORM_LIGHT_POSITION_02_MIRROR_SPECULAR; 
                                  GLuint      UNIFORM_LIGHT_POSITION_03_MIRROR_SPECULAR; 
                                  
                                  GLuint      UNIFORM_ambient_MIRROR_SPECULAR;
                                  GLuint      UNIFORM_scaleInverse_NdotL1_MIRROR_SPECULAR;   
                                  //-------------------------------------------------------------------------------------|_CORRECTION_UNIFORMS
                                  GLuint      UNIFORM_offset_MIRROR_SPECULAR;                                                                                
                                  GLuint      UNIFORM_tileJump_MIRROR_SPECULAR;                                                                              
                                  //-------------------------------------------------------------------------------------|_MATRIX_UNIFORMS
                                  GLuint      UNIFORM_MODELVIEW_MIRROR_SPECULAR;                                                                             
                                  GLuint      UNIFORM_MODELVIEWPROJ_MIRROR_SPECULAR;                                                                         
                                  //GLuint    UNIFORM_MODELVIEWPROJ_INVERSE_MIRROR_SPECULAR;                                                                 
                                  GLuint      UNIFORM_LIGHT_MATRIX_MIRROR_SPECULAR;                                                                          
                                  GLuint      UNIFORM_TEXTURE_MATRIX_MIRROR_SPECULAR;                                                                        
                                  //-------------------------------------------------------------------------------------|_TEXTURE_UNIFORMS
                                  GLuint      UNIFORM_TEXTURE_SHADOW_MIRROR_SPECULAR;                                                                        
                                  GLuint      UNIFORM_TEXTURE_DOT3_MIRROR_SPECULAR;                                                                          
                                  GLuint      UNIFORM_TEXTURE_MIRROR_SPECULAR; 
