

 glUseProgram(globalIllumination_01_SHADER);          
          //------------------------------------------------------------------------------|__BUFFERS          
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                  
          glEnableVertexAttribArray(0);	                                                                                              
          glVertexAttribPointer(1,     2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                 
          glEnableVertexAttribArray(1);                                                                                               
          //------------------------------------------------------------------------------|__UNIFORMS                                 
          glUniform4f(UNIFORM_LIGHT_POSITION_01_globalIllumination_01,            globalIllumination_01_LIGHT_POSITION_01[0],                       
                                                                       globalIllumination_01_LIGHT_POSITION_01[1],                       
                                                                       globalIllumination_01_LIGHT_POSITION_01[2],                       
                                                                       globalIllumination_01_LIGHT_POSITION_01[3]);                      
           
          glUniform4f(UNIFORM_offset_globalIllumination_01,                       offset[0], 
                                                                       offset[1], 
                                                                       offset[2], 
                                                                       offset[3]);                               
                                                                                                       
          glUniform4f(UNIFORM_tileJump_globalIllumination_01,                     tileJump_globalIllumination_01[0],                                
                                                                       tileJump_globalIllumination_01[1],                                
                                                                       tileJump_globalIllumination_01[2],                                
                                                                       tileJump_globalIllumination_01[3]);                               
         
          glUniform1f(UNIFORM_ambient_globalIllumination_01,                      ambient_globalIllumination_01);  
          glUniform1f(UNIFORM_scaleInverse_NdotL1_globalIllumination_01,                      scaleInverse_NdotL1_globalIllumination_01);            
          //---------------------------------------------------------------------------------------------|__MATRICES
          glUniformMatrix4fv(UNIFORM_MODELVIEW_globalIllumination_01,       1, 0,         modelView);                                             
          glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_globalIllumination_01,   1, 0,         mvpMatrix);                                   
                                                                                                                                              //glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_INVERSE_globalIllumination_01, 1, 0, ModelViewProjectionInverse);                            
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_globalIllumination_01,    1, 0,         lightMatrix);                                           
          glUniformMatrix4fv(UNIFORM_TEXTURE_MATRIX_globalIllumination_01,  1, 0,         textureMatrix);                                       
          //---------------------------------------------------------------------------------------------|__TEXTURES                                 
          glUniform1i(UNIFORM_TEXTURE_SHADOW_globalIllumination_01, 2);                                                                      
          glUniform1i(UNIFORM_TEXTURE_DOT3_globalIllumination_01,   1);                                                                        
          glUniform1i(UNIFORM_TEXTURE_globalIllumination_01,        0);                                                        
