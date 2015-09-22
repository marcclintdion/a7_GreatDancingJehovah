         
                                  GLfloat     gaussianBlurVerticalPass_POSITION[]                 = { 0.0,  0.0,  0.0,  1.0};
                                  GLfloat     gaussianBlurVerticalPass_ROTATE[]                 = { 0.0,  0.0,  0.0,  1.0}; 
                                  GLfloat     gaussianBlurVerticalPass_SCALE                     = 1.0;                                   
                                   
                                  //--------------------------------------------------
                                  GLfloat     offset_gaussianBlurVerticalPass[]                 = { 0.0,  0.0,  0.0,  1.0};                                           
                                  GLfloat     tileJump_gaussianBlurVerticalPass[]               = { 0.0,  0.0,  0.0,  1.0};                                           
                                  //=====================================================================================|_SHADER
                                  GLuint      gaussianBlurVerticalPass_SHADER_VERTEX;                                                                                 
                                  GLuint      gaussianBlurVerticalPass_SHADER_FRAGMENT;                                                                               
                                  GLuint      gaussianBlurVerticalPass_SHADER;     
                                  //-------------------------------------------------------------------------------------|_CONFIGURABLE_UNIFORMS
                                  GLuint      UNIFORM_LIGHT_POSITION_01_gaussianBlurVerticalPass;                                                                     
                                  GLuint      UNIFORM_LIGHT_POSITION_02_gaussianBlurVerticalPass; 
                                  GLuint      UNIFORM_LIGHT_POSITION_03_gaussianBlurVerticalPass; 
                                  
                                  GLuint      UNIFORM_attenuation_gaussianBlurVerticalPass;
                                  GLuint      UNIFORM_counter_gaussianBlurVerticalPass;                                                                               
                                  //-------------------------------------------------------------------------------------|_CORRECTION_UNIFORMS
                                  GLuint      UNIFORM_offset_gaussianBlurVerticalPass;                                                                                
                                  GLuint      UNIFORM_tileJump_gaussianBlurVerticalPass;                                                                              
                                  //-------------------------------------------------------------------------------------|_MATRIX_UNIFORMS
                                  GLuint      UNIFORM_MODELVIEW_gaussianBlurVerticalPass;                                                                             
                                  GLuint      UNIFORM_MODELVIEWPROJ_gaussianBlurVerticalPass;                                                                         
                                  //GLuint    UNIFORM_MODELVIEWPROJ_INVERSE_gaussianBlurVerticalPass;                                                                 
                                  GLuint      UNIFORM_LIGHT_MATRIX_gaussianBlurVerticalPass;                                                                          
                                  GLuint      UNIFORM_TEXTURE_MATRIX_gaussianBlurVerticalPass;                                                                        
                                  //-------------------------------------------------------------------------------------|_TEXTURE_UNIFORMS
                                  GLuint      UNIFORM_TEXTURE_SHADOW_gaussianBlurVerticalPass;                                                                        
                                  GLuint      UNIFORM_TEXTURE_DOT3_gaussianBlurVerticalPass;                                                                          
                                  GLuint      UNIFORM_TEXTURE_gaussianBlurVerticalPass; 
