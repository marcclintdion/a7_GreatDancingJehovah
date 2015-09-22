                                  //GLfloat     baseLighting_LIGHT_POSITION_01[]      =  {0, 2.39002, 0, 1.0};//----------------QUADRATRIC_ATTENUATION
                                  //GLfloat     ambient_baseLighting                  =   0.175;
                               
                                  
                                  
                                  GLfloat     gaussianBlurHorizontalPass_POSITION[]                 = { 0.0,  0.0,  0.0,  1.0}; 
                                  GLfloat     gaussianBlurHorizontalPass_ROTATE[]                 = { 0.0,  0.0,  0.0,  1.0}; 
                                  GLfloat     gaussianBlurHorizontalPass_SCALE                     = 1.0; 
                                  
                                  //--------------------------------------------------
                                  GLfloat     offset_gaussianBlurHorizontalPass[]                 = { 0.0,  0.0,  0.0,  1.0};                                           
                                  GLfloat     tileJump_gaussianBlurHorizontalPass[]               = { 0.0,  0.0,  0.0,  1.0};                                           
                                  //=====================================================================================|_SHADER
                                  GLuint      gaussianBlurHorizontalPass_SHADER_VERTEX;                                                                                 
                                  GLuint      gaussianBlurHorizontalPass_SHADER_FRAGMENT;                                                                               
                                  GLuint      gaussianBlurHorizontalPass_SHADER;     
                                  //-------------------------------------------------------------------------------------|_CONFIGURABLE_UNIFORMS
                                  GLuint      UNIFORM_LIGHT_POSITION_01_gaussianBlurHorizontalPass;                                                                     
                                  GLuint      UNIFORM_LIGHT_POSITION_02_gaussianBlurHorizontalPass; 
                                  GLuint      UNIFORM_LIGHT_POSITION_03_gaussianBlurHorizontalPass; 
                                  
                                  GLuint      UNIFORM_attenuation_gaussianBlurHorizontalPass;
                                  GLuint      UNIFORM_counter_gaussianBlurHorizontalPass;                                                                               
                                  //-------------------------------------------------------------------------------------|_CORRECTION_UNIFORMS
                                  GLuint      UNIFORM_offset_gaussianBlurHorizontalPass;                                                                                
                                  GLuint      UNIFORM_tileJump_gaussianBlurHorizontalPass;                                                                              
                                  //-------------------------------------------------------------------------------------|_MATRIX_UNIFORMS
                                  GLuint      UNIFORM_MODELVIEW_gaussianBlurHorizontalPass;                                                                             
                                  GLuint      UNIFORM_MODELVIEWPROJ_gaussianBlurHorizontalPass;                                                                         
                                  //GLuint    UNIFORM_MODELVIEWPROJ_INVERSE_gaussianBlurHorizontalPass;                                                                 
                                  GLuint      UNIFORM_LIGHT_MATRIX_gaussianBlurHorizontalPass;                                                                          
                                  GLuint      UNIFORM_TEXTURE_MATRIX_gaussianBlurHorizontalPass;                                                                        
                                  //-------------------------------------------------------------------------------------|_TEXTURE_UNIFORMS
                                  GLuint      UNIFORM_TEXTURE_SHADOW_gaussianBlurHorizontalPass;                                                                        
                                  GLuint      UNIFORM_TEXTURE_DOT3_gaussianBlurHorizontalPass;                                                                          
                                  GLuint      UNIFORM_TEXTURE_gaussianBlurHorizontalPass; 
