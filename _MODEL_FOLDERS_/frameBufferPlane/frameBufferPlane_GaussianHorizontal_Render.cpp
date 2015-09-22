    glUseProgram(frameBufferPlane_GaussianHorizontal_SHADER);                                                                                                                                              
    glBindBuffer(GL_ARRAY_BUFFER, frameBufferPlane_GaussianHorizontal_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, frameBufferPlane_GaussianHorizontal_POSITION[0], frameBufferPlane_GaussianHorizontal_POSITION[1], frameBufferPlane_GaussianHorizontal_POSITION[2]);                                                                                         
    Rotate(modelView, frameBufferPlane_GaussianHorizontal_ROTATE[0], frameBufferPlane_GaussianHorizontal_ROTATE[1], frameBufferPlane_GaussianHorizontal_ROTATE[2], frameBufferPlane_GaussianHorizontal_ROTATE[3]);//--MODEL                                                                       
    Scale(modelView, frameBufferPlane_GaussianHorizontal_SCALE[0], frameBufferPlane_GaussianHorizontal_SCALE[1], frameBufferPlane_GaussianHorizontal_SCALE[2]);     
    MultiplyMatrix(mvpMatrix, ScreenBufferMatrix, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                
    Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                         
    Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                      
    //======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_frameBufferPlane_GaussianHorizontal, frameBufferPlane_GaussianHorizontal_LIGHT_POSITION_01[0], frameBufferPlane_GaussianHorizontal_LIGHT_POSITION_01[1], frameBufferPlane_GaussianHorizontal_LIGHT_POSITION_01[2], frameBufferPlane_GaussianHorizontal_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_frameBufferPlane_GaussianHorizontal, frameBufferPlane_GaussianHorizontal_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_frameBufferPlane_GaussianHorizontal, frameBufferPlane_GaussianHorizontal_ATTENUATION); 
    glUniform1f(UNIFORM_ratio_Global_2_Component_frameBufferPlane_GaussianHorizontal, frameBufferPlane_GaussianHorizontal_ratio_Global_2_Component);     
    glUniform1f(UNIFORM_SHADER_SELECTION_frameBufferPlane_GaussianHorizontal, SHADER_SELECTION);                  
                                                                                                                    
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_frameBufferPlane_GaussianHorizontal,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_frameBufferPlane_GaussianHorizontal,    1,0,  lightMatrix);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_2_frameBufferPlane_GaussianHorizontal, 1);                                                                                                                             
    glUniform1i (UNIFORM_TEXTURE_frameBufferPlane_GaussianHorizontal, 0 );                                                                                                                                 
    //======================================================================================================                                                                  
    
                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 6);                                                                                                     

