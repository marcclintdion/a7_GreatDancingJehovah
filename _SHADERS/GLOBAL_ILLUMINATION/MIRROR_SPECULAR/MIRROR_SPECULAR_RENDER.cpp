

 glUseProgram(MIRROR_SPECULAR_SHADER);          
          //------------------------------------------------------------------------------|__BUFFERS          
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                  
          glEnableVertexAttribArray(0);	                                                                                              
        //glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                 
        //glEnableVertexAttribArray(0);	                                                                                          
          glVertexAttribPointer(1,     2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                 
          glEnableVertexAttribArray(1);                                                                                               
          //------------------------------------------------------------------------------|__UNIFORMS                                 
          glUniform4f(UNIFORM_LIGHT_POSITION_01_MIRROR_SPECULAR,            MIRROR_SPECULAR_LIGHT_POSITION_01[0],                       
                                                                       MIRROR_SPECULAR_LIGHT_POSITION_01[1],                       
                                                                       MIRROR_SPECULAR_LIGHT_POSITION_01[2],                       
                                                                       MIRROR_SPECULAR_LIGHT_POSITION_01[3]);                      
           
          glUniform4f(UNIFORM_offset_MIRROR_SPECULAR,                       offset[0], 
                                                                       offset[1], 
                                                                       offset[2], 
                                                                       offset[3]);                               
                                                                                                       
          glUniform4f(UNIFORM_tileJump_MIRROR_SPECULAR,                     tileJump_MIRROR_SPECULAR[0],                                
                                                                       tileJump_MIRROR_SPECULAR[1],                                
                                                                       tileJump_MIRROR_SPECULAR[2],                                
                                                                       tileJump_MIRROR_SPECULAR[3]);                               
         
          glUniform1f(UNIFORM_ambient_MIRROR_SPECULAR,                      ambient_MIRROR_SPECULAR);   
          glUniform1f(UNIFORM_scaleInverse_NdotL1_MIRROR_SPECULAR,          scaleInverse_NdotL1_MIRROR_SPECULAR);           
          //---------------------------------------------------------------------------------------------|__MATRICES
          glUniformMatrix4fv(UNIFORM_MODELVIEW_MIRROR_SPECULAR,       1, 0,         modelView);                                             
          glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_MIRROR_SPECULAR,   1, 0,         mvpMatrix);                                   
                                                                                                                                              //glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_INVERSE_MIRROR_SPECULAR, 1, 0, ModelViewProjectionInverse);                            
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_MIRROR_SPECULAR,    1, 0,         lightMatrix);                                           
          glUniformMatrix4fv(UNIFORM_TEXTURE_MATRIX_MIRROR_SPECULAR,  1, 0,         textureMatrix);                                       
          //---------------------------------------------------------------------------------------------|__TEXTURES                                 
          glUniform1i(UNIFORM_TEXTURE_SHADOW_MIRROR_SPECULAR, 2);                                                                      
          glUniform1i(UNIFORM_TEXTURE_DOT3_MIRROR_SPECULAR,   1);                                                                        
          glUniform1i(UNIFORM_TEXTURE_MIRROR_SPECULAR,        0);                                                        
