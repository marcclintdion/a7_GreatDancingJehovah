                                  //GLfloat     goldenSunset_LIGHT_POSITION_01[]      =  {0, 2.39002, 0, 1.0};//----------------QUADRATRIC_ATTENUATION
                                  //GLfloat     ambient_goldenSunset                  =   0.175;
                               
                                  
                                  //--------------------------------------------------
                                  GLfloat     offset_globalIllumination_02[]                 = { 0.0,  0.0,  0.0,  1.0};                                           
                                  GLfloat     tileJump_globalIllumination_02[]               = { 0.0,  0.0,  0.0,  1.0};                                           
                                  //=====================================================================================|_SHADER
                                  GLuint      globalIllumination_02_SHADER_VERTEX;                                                                                 
                                  GLuint      globalIllumination_02_SHADER_FRAGMENT;                                                                               
                                  GLuint      globalIllumination_02_SHADER;     
                                  //-------------------------------------------------------------------------------------|_CONFIGURABLE_UNIFORMS
                                  GLuint      UNIFORM_LIGHT_POSITION_01_globalIllumination_02;                                                                     
                                  GLuint      UNIFORM_LIGHT_POSITION_02_globalIllumination_02; 
                                  GLuint      UNIFORM_LIGHT_POSITION_03_globalIllumination_02; 
                                  
                                  GLuint      UNIFORM_ambient_globalIllumination_02;
                                  GLuint      UNIFORM_scaleInverse_NdotL1_globalIllumination_02;   
                                  //-------------------------------------------------------------------------------------|_CORRECTION_UNIFORMS
                                  GLuint      UNIFORM_offset_globalIllumination_02;                                                                                
                                  GLuint      UNIFORM_tileJump_globalIllumination_02;                                                                              
                                  //-------------------------------------------------------------------------------------|_MATRIX_UNIFORMS
                                  GLuint      UNIFORM_MODELVIEW_globalIllumination_02;                                                                             
                                  GLuint      UNIFORM_MODELVIEWPROJ_globalIllumination_02;                                                                         
                                  //GLuint    UNIFORM_MODELVIEWPROJ_INVERSE_globalIllumination_02;                                                                 
                                  GLuint      UNIFORM_LIGHT_MATRIX_globalIllumination_02;                                                                          
                                  GLuint      UNIFORM_TEXTURE_MATRIX_globalIllumination_02;                                                                        
                                  //-------------------------------------------------------------------------------------|_TEXTURE_UNIFORMS
                                  GLuint      UNIFORM_TEXTURE_SHADOW_globalIllumination_02;                                                                        
                                  GLuint      UNIFORM_TEXTURE_DOT3_globalIllumination_02;                                                                          
                                  GLuint      UNIFORM_TEXTURE_globalIllumination_02; 
