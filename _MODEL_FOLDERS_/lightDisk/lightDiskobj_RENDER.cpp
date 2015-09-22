    glBindBuffer(GL_ARRAY_BUFFER, lightDiskobj_VBO);                                                                                                                                
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lightDiskobj_INDICES_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, moveSet[0], moveSet[1], moveSet[2]);       
    Translate(modelView, lightDiskobj_POSITION[0], lightDiskobj_POSITION[1], lightDiskobj_POSITION[2]);                                                                                         
    Rotate(modelView, lightDiskobj_ROTATE[0], lightDiskobj_ROTATE[1], lightDiskobj_ROTATE[2], lightDiskobj_ROTATE[3]);//--MODEL                                                                       
    Scale(modelView, lightDiskobj_SCALE[0], lightDiskobj_SCALE[1], lightDiskobj_SCALE[2]);//--MODEL       
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                
    //======================================================================================================                                                                  

ShaderSelection();  

    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, lightDiskobj_NORMALMAP);                                                                                                                          
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, lightDiskobj_TEXTUREMAP);                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawElements(GL_TRIANGLES, 42, GL_UNSIGNED_INT, 0);                                                                                                     

