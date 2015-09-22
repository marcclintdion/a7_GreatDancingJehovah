    glEnable(GL_BLEND);
   
                                                                                                                                                
    glBindBuffer(GL_ARRAY_BUFFER, spring_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, spring_POSITION[0] + moveSet[0], spring_POSITION[1] + moveSet[1], spring_POSITION[2] + moveSet[2]);                                                                                         
    Rotate(modelView, spring_ROTATE[0], spring_ROTATE[1], spring_ROTATE[2], spring_ROTATE[3]);//--MODEL                                                                       
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                
    Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
    Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                      
    //======================================================================================================                                                                  
 
ShaderSelection();
 

if(SHADER_SELECTION == 0)
{  
    glUseProgram(spring_SHADER);    
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_spring, spring_LIGHT_POSITION_01[0], spring_LIGHT_POSITION_01[1], spring_LIGHT_POSITION_01[2], spring_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_spring, spring_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_spring, spring_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_spring,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_spring,    1,0,  lightMatrix);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_spring, 1); 
    glUniform1i (UNIFORM_TEXTURE_spring, 0 ); 
}   
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, spring_NORMALMAP);                                                                                                                          
                                                                                                                                
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, spring_TEXTUREMAP);                                                                                                                            
                                                                                                                                    
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 72 * 4);                                                                                                     
    
    glDisable(GL_BLEND);
