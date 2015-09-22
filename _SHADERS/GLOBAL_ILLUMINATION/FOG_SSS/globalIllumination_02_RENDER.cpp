

 glUseProgram(globalIllumination_02_SHADER);          
          //------------------------------------------------------------------------------|__BUFFERS          
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                  
          glEnableVertexAttribArray(0);	                                                                                              
        //glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                 
        //glEnableVertexAttribArray(0);	                                                                                          
          glVertexAttribPointer(1,     2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                 
          glEnableVertexAttribArray(1);                                                                                               
          //------------------------------------------------------------------------------|__UNIFORMS                                 
          glUniform4f(UNIFORM_LIGHT_POSITION_01_globalIllumination_02,            globalIllumination_02_LIGHT_POSITION_01[0],                       
                                                                       globalIllumination_02_LIGHT_POSITION_01[1],                       
                                                                       globalIllumination_02_LIGHT_POSITION_01[2],                       
                                                                       globalIllumination_02_LIGHT_POSITION_01[3]);                      
           
          glUniform4f(UNIFORM_offset_globalIllumination_02,                       offset[0], 
                                                                       offset[1], 
                                                                       offset[2], 
                                                                       offset[3]);                               
                                                                                                       
          glUniform4f(UNIFORM_tileJump_globalIllumination_02,                     tileJump_globalIllumination_02[0],                                
                                                                       tileJump_globalIllumination_02[1],                                
                                                                       tileJump_globalIllumination_02[2],                                
                                                                       tileJump_globalIllumination_02[3]);                               
         
          glUniform1f(UNIFORM_ambient_globalIllumination_02,                      ambient_globalIllumination_02);   
          glUniform1f(UNIFORM_scaleInverse_NdotL1_globalIllumination_02,          scaleInverse_NdotL1_globalIllumination_02);           
          //---------------------------------------------------------------------------------------------|__MATRICES
          glUniformMatrix4fv(UNIFORM_MODELVIEW_globalIllumination_02,       1, 0,         modelView);                                             
          glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_globalIllumination_02,   1, 0,         mvpMatrix);                                   
                                                                                                                                              //glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_INVERSE_globalIllumination_02, 1, 0, ModelViewProjectionInverse);                            
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_globalIllumination_02,    1, 0,         lightMatrix);                                           
          glUniformMatrix4fv(UNIFORM_TEXTURE_MATRIX_globalIllumination_02,  1, 0,         textureMatrix);                                       
          //---------------------------------------------------------------------------------------------|__TEXTURES                                 
          glUniform1i(UNIFORM_TEXTURE_SHADOW_globalIllumination_02, 2);                                                                      
          glUniform1i(UNIFORM_TEXTURE_DOT3_globalIllumination_02,   1);                                                                        
          glUniform1i(UNIFORM_TEXTURE_globalIllumination_02,        0);                                                        
