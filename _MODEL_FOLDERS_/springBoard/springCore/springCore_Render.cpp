                                                                                                                                                
    glBindBuffer(GL_ARRAY_BUFFER, springCore_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, springCore_POSITION[0] + moveSet[0], springCore_POSITION[1] + moveSet[1], springCore_POSITION[2] + moveSet[2]);                                                                                         
    Rotate(modelView, springCore_ROTATE[0], springCore_ROTATE[1], springCore_ROTATE[2], springCore_ROTATE[3]);//--MODEL                                                                       
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
    glUseProgram(springCore_SHADER);  
    
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_springCore, springCore_LIGHT_POSITION_01[0], springCore_LIGHT_POSITION_01[1], springCore_LIGHT_POSITION_01[2], springCore_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_springCore, springCore_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_springCore, springCore_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_springCore,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_springCore,    1,0,  lightMatrix);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_springCore, 1); 
    glUniform1i (UNIFORM_TEXTURE_springCore, 0 );
}    
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, springCore_NORMALMAP);                                                                                                                          
                                                                                                                                
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, springCore_TEXTUREMAP);                                                                                                                            
                                                                                                                                    
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 174*4);                                                                                                     

