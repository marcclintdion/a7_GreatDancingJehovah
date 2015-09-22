    glUseProgram(foliageRockRing_SHADER);                                                                                                                                              
    glBindBuffer(GL_ARRAY_BUFFER, foliageRockRing_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, foliageRockRing_POSITION[0], foliageRockRing_POSITION[1], foliageRockRing_POSITION[2]);                                                                                         
    Rotate(modelView, foliageRockRing_ROTATE[0], foliageRockRing_ROTATE[1], foliageRockRing_ROTATE[2], foliageRockRing_ROTATE[3]);//--MODEL                                                                       
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
    glUniform4f(UNIFORM_LIGHT_POSITION_01_foliageRockRing, foliageRockRing_LIGHT_POSITION_01[0], foliageRockRing_LIGHT_POSITION_01[1], foliageRockRing_LIGHT_POSITION_01[2], foliageRockRing_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_foliageRockRing, foliageRockRing_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_foliageRockRing, foliageRockRing_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_foliageRockRing,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_foliageRockRing,    1,0,  lightMatrix);                                                                                                    
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, foliageRockRing_NORMALMAP);                                                                                                                          
    glUniform1i (UNIFORM_TEXTURE_DOT3_foliageRockRing, 1);                                                                                                                             
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, foliageRockRing_TEXTUREMAP);                                                                                                                            
    glUniform1i (UNIFORM_TEXTURE_foliageRockRing, 0 );                                                                                                                                 
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 1620);                                                                                                     

