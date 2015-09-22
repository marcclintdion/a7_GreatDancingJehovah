                                  //GLfloat     baseLighting_LIGHT_POSITION_01[]      =  {0, 2.39002, 0, 1.0};//----------------QUADRATRIC_ATTENUATION
                                  //GLfloat     ambient_baseLighting                  =   0.175;
                               
                                  
                                  //--------------------------------------------------
                                  GLfloat     offset_baseLighting[]                 = { 0.0,  0.0,  0.0,  1.0};                                           
                                  GLfloat     tileJump_baseLighting[]               = { 0.0,  0.0,  0.0,  1.0};                                           
                                  //=====================================================================================|_SHADER
                                  GLuint      baseLighting_SHADER_VERTEX;                                                                                 
                                  GLuint      baseLighting_SHADER_FRAGMENT;                                                                               
                                  GLuint      baseLighting_SHADER;     
                                  //-------------------------------------------------------------------------------------|_CONFIGURABLE_UNIFORMS
                                  GLuint      UNIFORM_LIGHT_POSITION_01_baseLighting;                                                                     
                                  GLuint      UNIFORM_LIGHT_POSITION_02_baseLighting; 
                                  GLuint      UNIFORM_LIGHT_POSITION_03_baseLighting; 
                                  
                                  GLuint      UNIFORM_attenuation_baseLighting;
                                  GLuint      UNIFORM_counter_baseLighting;                                                                               
                                  //-------------------------------------------------------------------------------------|_CORRECTION_UNIFORMS
                                  GLuint      UNIFORM_offset_baseLighting;                                                                                
                                  GLuint      UNIFORM_tileJump_baseLighting;                                                                              
                                  //-------------------------------------------------------------------------------------|_MATRIX_UNIFORMS
                                  GLuint      UNIFORM_MODELVIEW_baseLighting;                                                                             
                                  GLuint      UNIFORM_MODELVIEWPROJ_baseLighting;                                                                         
                                  //GLuint    UNIFORM_MODELVIEWPROJ_INVERSE_baseLighting;                                                                 
                                  GLuint      UNIFORM_LIGHT_MATRIX_baseLighting;                                                                          
                                  GLuint      UNIFORM_TEXTURE_MATRIX_baseLighting;                                                                        
                                  //-------------------------------------------------------------------------------------|_TEXTURE_UNIFORMS
                                  GLuint      UNIFORM_TEXTURE_SHADOW_baseLighting;                                                                        
                                  GLuint      UNIFORM_TEXTURE_DOT3_baseLighting;                                                                          
                                  GLuint      UNIFORM_TEXTURE_baseLighting; 
