    glUseProgram(rockRing_SHADER);                                                                                                                                              
    glBindBuffer(GL_ARRAY_BUFFER, rockRing_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, rockRing_POSITION[0], rockRing_POSITION[1], rockRing_POSITION[2]);                                                                                         
    Rotate(modelView, rockRing_ROTATE[0], rockRing_ROTATE[1], rockRing_ROTATE[2], rockRing_ROTATE[3]);//--MODEL                                                                       
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                
    Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
    Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                      
    //======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_rockRing, rockRing_LIGHT_POSITION_01[0], rockRing_LIGHT_POSITION_01[1], rockRing_LIGHT_POSITION_01[2], rockRing_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_rockRing, rockRing_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_rockRing, rockRing_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_rockRing,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_rockRing,    1,0,  lightMatrix);                                                                                                    
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, rockRing_NORMALMAP);                                                                                                                          
    glUniform1i (UNIFORM_TEXTURE_DOT3_rockRing, 1);                                                                                                                             
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, rockRing_TEXTUREMAP);                                                                                                                            
    glUniform1i (UNIFORM_TEXTURE_rockRing, 0 );                                                                                                                                 
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 399);                                                                                                     

