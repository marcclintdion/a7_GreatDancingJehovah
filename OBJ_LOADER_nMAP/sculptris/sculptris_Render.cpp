    glUseProgram(sculptris_SHADER);                                                                                                                                              
    glBindBuffer(GL_ARRAY_BUFFER, sculptris_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, sculptris_POSITION[0], sculptris_POSITION[1], sculptris_POSITION[2]);                                                                                         
    Rotate(modelView, sculptris_ROTATE[0], sculptris_ROTATE[1], sculptris_ROTATE[2], sculptris_ROTATE[3]);//--MODEL                                                                       
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                
    Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                         
    Rotate(lightMatrix,1.0, 0.0, 0.0,  look_UP_DOWN);                                                                                                                      
    //======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_sculptris, sculptris_LIGHT_POSITION_01[0], sculptris_LIGHT_POSITION_01[1], sculptris_LIGHT_POSITION_01[2], sculptris_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_sculptris, sculptris_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_sculptris, sculptris_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_sculptris,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_sculptris,    1,0,  lightMatrix);                                                                                                    
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, sculptris_NORMALMAP);                                                                                                                          
    glUniform1i (UNIFORM_TEXTURE_DOT3_sculptris, 1);                                                                                                                             
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, sculptris_TEXTUREMAP);                                                                                                                            
    glUniform1i (UNIFORM_TEXTURE_sculptris, 0 );                                                                                                                                 
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 1584);                                                                                                     

