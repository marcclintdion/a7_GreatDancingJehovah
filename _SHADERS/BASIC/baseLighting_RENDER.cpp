                baseLighting_LIGHT_POSITION_01[0]                            =  backGroundLight_01_POSITION[0];  
                baseLighting_LIGHT_POSITION_01[1]                            =  backGroundLight_01_POSITION[1]; 
                baseLighting_LIGHT_POSITION_01[2]                            =  backGroundLight_01_POSITION[2];


 glUseProgram(baseLighting_SHADER);          
          //------------------------------------------------------------------------------|__BUFFERS          
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                  
          glEnableVertexAttribArray(0);	                                                                                              
        //glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                 
        //glEnableVertexAttribArray(0);	                                                                                          
          glVertexAttribPointer(1,     2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                 
          glEnableVertexAttribArray(1);                                                                                               
          //------------------------------------------------------------------------------|__UNIFORMS                                 
          glUniform4f(UNIFORM_LIGHT_POSITION_01_baseLighting,          baseLighting_LIGHT_POSITION_01[0],                       
                                                                       baseLighting_LIGHT_POSITION_01[1],                       
                                                                       baseLighting_LIGHT_POSITION_01[2],                       
                                                                       baseLighting_LIGHT_POSITION_01[3]);                      
           
          glUniform4f(UNIFORM_offset_baseLighting,                     offset[0], 
                                                                       offset[1], 
                                                                       offset[2], 
                                                                       offset[3]);                               
                                                                                                       
          glUniform4f(UNIFORM_tileJump_baseLighting,                   tileJump_baseLighting[0],                                
                                                                       tileJump_baseLighting[1],                                
                                                                       tileJump_baseLighting[2],                                
                                                                       tileJump_baseLighting[3]);                               
         
          glUniform1f(UNIFORM_attenuation_baseLighting,                ambient_baseLighting);   
          glUniform1f(UNIFORM_counter_baseLighting,                    globalLinearAttenuation);                  
          //---------------------------------------------------------------------------------------------|__MATRICES
          glUniformMatrix4fv(UNIFORM_MODELVIEW_baseLighting,       1, 0,         modelView);                                             
          glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_baseLighting,   1, 0,         mvpMatrix);                                   
                                                                                                                                              //glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_INVERSE_baseLighting, 1, 0, ModelViewProjectionInverse);                            
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_baseLighting,    1, 0,         lightMatrix);                                           
          glUniformMatrix4fv(UNIFORM_TEXTURE_MATRIX_baseLighting,  1, 0,         textureMatrix);                                       
          //---------------------------------------------------------------------------------------------|__TEXTURES                                 
          glUniform1i(UNIFORM_TEXTURE_SHADOW_baseLighting, 2);                                                                      
          glUniform1i(UNIFORM_TEXTURE_DOT3_baseLighting,   1);                                                                        
          glUniform1i(UNIFORM_TEXTURE_baseLighting,        0);                                                        
